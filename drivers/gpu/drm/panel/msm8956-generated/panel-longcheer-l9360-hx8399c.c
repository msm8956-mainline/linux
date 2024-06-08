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

struct booyi_hx8399c {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data booyi_hx8399c_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline struct booyi_hx8399c *to_booyi_hx8399c(struct drm_panel *panel)
{
	return container_of(panel, struct booyi_hx8399c, panel);
}

static void booyi_hx8399c_reset(struct booyi_hx8399c *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(50);
}

static int booyi_hx8399c_on(struct booyi_hx8399c *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0xff, 0x83, 0x99);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba,
					 0x63, 0x03, 0x68, 0x63);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1,
					 0x02, 0x04, 0x6a, 0x8a, 0x01, 0x32,
					 0x33, 0x11, 0x11, 0x4d, 0x4d, 0x56,
					 0x73, 0x02, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2,
					 0x00, 0x80, 0x80, 0xae, 0x05, 0x07,
					 0x5a, 0x11, 0x10, 0x10, 0x00, 0x1e,
					 0x70, 0x03, 0xd4);
	mipi_dsi_usleep_range(&dsi_ctx, 10000, 11000);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4,
					 0x00, 0xff, 0x10, 0x18, 0x04, 0x9a,
					 0x00, 0x00, 0x06, 0x00, 0x02, 0x04,
					 0x00, 0x24, 0x02, 0x04, 0x0a, 0x26,
					 0x03, 0x00, 0x00, 0x00, 0xff, 0x00,
					 0x10, 0x18, 0x04, 0x9a, 0x00, 0x00,
					 0x08, 0x00, 0x02, 0x04, 0x00, 0x24,
					 0x02, 0x04, 0x0a, 0x00, 0x00, 0x02,
					 0x9f, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3,
					 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00,
					 0x30, 0x00, 0x00, 0x00, 0x05, 0x00,
					 0x05, 0x00, 0x07, 0x88, 0x07, 0x88,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x15,
					 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
					 0x00, 0x05, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5,
					 0x20, 0x20, 0x19, 0x19, 0x18, 0x18,
					 0x01, 0x01, 0x00, 0x00, 0x25, 0x25,
					 0x18, 0x18, 0x18, 0x18, 0x24, 0x24,
					 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
					 0x18, 0x18, 0x2f, 0x2f, 0x30, 0x30,
					 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6,
					 0x24, 0x24, 0x18, 0x18, 0x19, 0x19,
					 0x00, 0x00, 0x01, 0x01, 0x25, 0x25,
					 0x18, 0x18, 0x18, 0x18, 0x20, 0x20,
					 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
					 0x18, 0x18, 0x2f, 0x2f, 0x30, 0x30,
					 0x31, 0x31);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0xaa, 0x8a, 0xaa, 0xaa, 0xaa, 0x8a,
					 0xaa, 0xaa, 0xaa, 0x8a, 0xaa, 0xaa,
					 0xaa, 0x8a, 0xaa, 0xaa);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0xff, 0xfc, 0xc0, 0x3f, 0xff, 0xfc,
					 0xc0, 0x3f, 0xff, 0xfc, 0xc0, 0x3f,
					 0xff, 0xfc, 0xc0, 0x3f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8,
					 0xff, 0xfc, 0xc0, 0x3f, 0xff, 0xfc,
					 0xc0, 0x3f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe0,
					 0x07, 0x18, 0x21, 0x1c, 0x40, 0x49,
					 0x56, 0x53, 0x5c, 0x67, 0x70, 0x78,
					 0x7c, 0x84, 0x8c, 0x91, 0x96, 0x9d,
					 0x9e, 0xa5, 0x98, 0xa6, 0xa8, 0x55,
					 0x4e, 0x52, 0x53, 0x07, 0x18, 0x21,
					 0x1c, 0x40, 0x49, 0x56, 0x53, 0x5c,
					 0x67, 0x70, 0x78, 0x7c, 0x84, 0x8c,
					 0x91, 0x96, 0x9d, 0x9e, 0xa5, 0x98,
					 0xa6, 0xa8, 0x55, 0x4e, 0x52, 0x53);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x82, 0x82);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x36, 0x02);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);

	return dsi_ctx.accum_err;
}

static int booyi_hx8399c_off(struct booyi_hx8399c *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 100);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0xff, 0x83, 0x99);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x01);

	return dsi_ctx.accum_err;
}

static int booyi_hx8399c_prepare(struct drm_panel *panel)
{
	struct booyi_hx8399c *ctx = to_booyi_hx8399c(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(booyi_hx8399c_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	booyi_hx8399c_reset(ctx);

	ret = booyi_hx8399c_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(booyi_hx8399c_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int booyi_hx8399c_unprepare(struct drm_panel *panel)
{
	struct booyi_hx8399c *ctx = to_booyi_hx8399c(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = booyi_hx8399c_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(booyi_hx8399c_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode booyi_hx8399c_mode = {
	.clock = (1080 + 65 + 60 + 81) * (1920 + 32 + 4 + 26) * 56 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 65,
	.hsync_end = 1080 + 65 + 60,
	.htotal = 1080 + 65 + 60 + 81,
	.vdisplay = 1920,
	.vsync_start = 1920 + 32,
	.vsync_end = 1920 + 32 + 4,
	.vtotal = 1920 + 32 + 4 + 26,
	.width_mm = 62,
	.height_mm = 111,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int booyi_hx8399c_get_modes(struct drm_panel *panel,
				   struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &booyi_hx8399c_mode);
}

static const struct drm_panel_funcs booyi_hx8399c_panel_funcs = {
	.prepare = booyi_hx8399c_prepare,
	.unprepare = booyi_hx8399c_unprepare,
	.get_modes = booyi_hx8399c_get_modes,
};

static int booyi_hx8399c_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct booyi_hx8399c *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct booyi_hx8399c, panel,
				   &booyi_hx8399c_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(booyi_hx8399c_supplies),
					    booyi_hx8399c_supplies,
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

static void booyi_hx8399c_remove(struct mipi_dsi_device *dsi)
{
	struct booyi_hx8399c *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id booyi_hx8399c_of_match[] = {
	{ .compatible = "longcheer,l9360-hx8399c" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, booyi_hx8399c_of_match);

static struct mipi_dsi_driver booyi_hx8399c_driver = {
	.probe = booyi_hx8399c_probe,
	.remove = booyi_hx8399c_remove,
	.driver = {
		.name = "panel-booyi-hx8399c",
		.of_match_table = booyi_hx8399c_of_match,
	},
};
module_mipi_dsi_driver(booyi_hx8399c_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for booyi HX8399C 1080p video mode dsi panel");
MODULE_LICENSE("GPL");
