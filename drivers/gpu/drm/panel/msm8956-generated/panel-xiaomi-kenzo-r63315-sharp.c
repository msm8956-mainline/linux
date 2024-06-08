// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct sharp_r63315 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data sharp_r63315_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline struct sharp_r63315 *to_sharp_r63315(struct drm_panel *panel)
{
	return container_of(panel, struct sharp_r63315, panel);
}

static void sharp_r63315_reset(struct sharp_r63315 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(30);
}

static int sharp_r63315_on(struct sharp_r63315 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x35, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x55, 0x00);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int sharp_r63315_off(struct sharp_r63315 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 150);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 150);

	return dsi_ctx.accum_err;
}

static int sharp_r63315_prepare(struct drm_panel *panel)
{
	struct sharp_r63315 *ctx = to_sharp_r63315(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(sharp_r63315_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	sharp_r63315_reset(ctx);

	ret = sharp_r63315_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(sharp_r63315_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int sharp_r63315_unprepare(struct drm_panel *panel)
{
	struct sharp_r63315 *ctx = to_sharp_r63315(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = sharp_r63315_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(sharp_r63315_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode sharp_r63315_mode = {
	.clock = (1080 + 98 + 8 + 98) * (1920 + 10 + 2 + 8) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 98,
	.hsync_end = 1080 + 98 + 8,
	.htotal = 1080 + 98 + 8 + 98,
	.vdisplay = 1920,
	.vsync_start = 1920 + 10,
	.vsync_end = 1920 + 10 + 2,
	.vtotal = 1920 + 10 + 2 + 8,
	.width_mm = 70,
	.height_mm = 128,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int sharp_r63315_get_modes(struct drm_panel *panel,
				  struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &sharp_r63315_mode);
}

static const struct drm_panel_funcs sharp_r63315_panel_funcs = {
	.prepare = sharp_r63315_prepare,
	.unprepare = sharp_r63315_unprepare,
	.get_modes = sharp_r63315_get_modes,
};

static int sharp_r63315_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct sharp_r63315 *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct sharp_r63315, panel,
				   &sharp_r63315_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(sharp_r63315_supplies),
					    sharp_r63315_supplies,
					    &ctx->supplies);
	if (ret < 0)
		return ret;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void sharp_r63315_remove(struct mipi_dsi_device *dsi)
{
	struct sharp_r63315 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id sharp_r63315_of_match[] = {
	{ .compatible = "xiaomi,kenzo-r63315-sharp" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, sharp_r63315_of_match);

static struct mipi_dsi_driver sharp_r63315_driver = {
	.probe = sharp_r63315_probe,
	.remove = sharp_r63315_remove,
	.driver = {
		.name = "panel-sharp-r63315",
		.of_match_table = sharp_r63315_of_match,
	},
};
module_mipi_dsi_driver(sharp_r63315_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for sharp r63315 1080p video mode dsi panel");
MODULE_LICENSE("GPL");
