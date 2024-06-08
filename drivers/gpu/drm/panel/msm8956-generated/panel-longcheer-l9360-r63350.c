// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2025 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct truly_r63350 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data truly_r63350_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline struct truly_r63350 *to_truly_r63350(struct drm_panel *panel)
{
	return container_of(panel, struct truly_r63350, panel);
}

static void truly_r63350_reset(struct truly_r63350 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int truly_r63350_on(struct truly_r63350 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x14, 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x0c, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x4b, 0xdb, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0x00, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1,
					 0x04, 0x60, 0x00, 0x20, 0x29, 0x41,
					 0x22, 0x63, 0xf0, 0xff, 0xff, 0x9b,
					 0x7b, 0xcf, 0xb5, 0xff, 0xff, 0x87,
					 0x8c, 0xc5, 0x11, 0x54, 0x02, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x22, 0x11,
					 0x02, 0x21, 0x00, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x31, 0xf7, 0x80, 0x08, 0x04, 0x00,
					 0x00, 0x08);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4,
					 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6,
					 0xc8, 0x3c, 0x3c, 0x07, 0x01, 0x07,
					 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e,
					 0x1a, 0x07, 0xc8);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7,
					 0x01, 0x0c, 0x13, 0x1c, 0x2a, 0x38,
					 0x43, 0x54, 0x39, 0x41, 0x4e, 0x5d,
					 0x6e, 0x78, 0x7c, 0x01, 0x0c, 0x13,
					 0x1c, 0x2a, 0x38, 0x43, 0x54, 0x39,
					 0x41, 0x4e, 0x5d, 0x6e, 0x78, 0x7c);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0xff, 0xe1, 0x87, 0xff, 0x00, 0x00,
					 0x00, 0x00, 0xff, 0xe1, 0x87, 0xff,
					 0xe8, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0,
					 0x11, 0x00, 0x00, 0x57, 0xd7, 0x40,
					 0x19, 0x19, 0x09, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1,
					 0x00, 0x48, 0x16, 0x0f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x1b, 0x33, 0xbb, 0xbb, 0xb3, 0x33,
					 0x33, 0x33, 0x33, 0x00, 0x01, 0x00,
					 0x00, 0xd8, 0xa0, 0x0c, 0x23, 0x23,
					 0x33, 0x33, 0x72, 0x12, 0x8a, 0x57,
					 0x3d, 0xbc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5,
					 0x06, 0x00, 0x00, 0x01, 0x3e, 0x01,
					 0x3e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xde,
					 0x00, 0x3f, 0xff, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_ADDRESS_MODE, 0x00);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int truly_r63350_off(struct truly_r63350 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x01);

	return dsi_ctx.accum_err;
}

static int truly_r63350_prepare(struct drm_panel *panel)
{
	struct truly_r63350 *ctx = to_truly_r63350(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(truly_r63350_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	truly_r63350_reset(ctx);

	ret = truly_r63350_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(truly_r63350_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int truly_r63350_unprepare(struct drm_panel *panel)
{
	struct truly_r63350 *ctx = to_truly_r63350(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = truly_r63350_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(truly_r63350_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode truly_r63350_mode = {
	.clock = (1080 + 90 + 20 + 60) * (1920 + 7 + 2 + 7) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 90,
	.hsync_end = 1080 + 90 + 20,
	.htotal = 1080 + 90 + 20 + 60,
	.vdisplay = 1920,
	.vsync_start = 1920 + 7,
	.vsync_end = 1920 + 7 + 2,
	.vtotal = 1920 + 7 + 2 + 7,
	.width_mm = 62,
	.height_mm = 111,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int truly_r63350_get_modes(struct drm_panel *panel,
				  struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &truly_r63350_mode);
}

static const struct drm_panel_funcs truly_r63350_panel_funcs = {
	.prepare = truly_r63350_prepare,
	.unprepare = truly_r63350_unprepare,
	.get_modes = truly_r63350_get_modes,
};

static int truly_r63350_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct truly_r63350 *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct truly_r63350, panel,
				   &truly_r63350_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(truly_r63350_supplies),
					    truly_r63350_supplies,
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
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

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

static void truly_r63350_remove(struct mipi_dsi_device *dsi)
{
	struct truly_r63350 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id truly_r63350_of_match[] = {
	{ .compatible = "longcheer,l9360-r63350" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, truly_r63350_of_match);

static struct mipi_dsi_driver truly_r63350_driver = {
	.probe = truly_r63350_probe,
	.remove = truly_r63350_remove,
	.driver = {
		.name = "panel-truly-r63350",
		.of_match_table = truly_r63350_of_match,
	},
};
module_mipi_dsi_driver(truly_r63350_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for truly R63350 1080p video mode dsi panel");
MODULE_LICENSE("GPL");
