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

struct booyi_hx8399b_command {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data booyi_hx8399b_command_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline
struct booyi_hx8399b_command *to_booyi_hx8399b_command(struct drm_panel *panel)
{
	return container_of(panel, struct booyi_hx8399b_command, panel);
}

static void booyi_hx8399b_command_reset(struct booyi_hx8399b_command *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int booyi_hx8399b_command_on(struct booyi_hx8399b_command *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb9, 0xff, 0x83, 0x99);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1,
				     0x18, 0xac, 0x8c, 0x11, 0xd1, 0x23, 0x33,
				     0x11, 0xf1, 0x9e, 0x63);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb2,
				     0x00, 0x80, 0x00, 0x7f, 0x05, 0x07, 0x62,
				     0x4d, 0x11, 0x11, 0x00, 0x1c, 0x41, 0x00,
				     0x00, 0x08, 0x1c, 0x0b, 0x62, 0x00, 0x09,
				     0xdb, 0xdb, 0x24);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4,
				     0x00, 0xff, 0x05, 0xb7, 0x59, 0x59, 0x05,
				     0xb7, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x04,
				     0x00, 0x2a, 0x05, 0x05, 0x0b, 0x00, 0x33,
				     0x0e, 0xb0, 0x05, 0xb7, 0x59, 0x59, 0x05,
				     0xb7, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x04,
				     0x00, 0x2a, 0x05, 0x05, 0x0b, 0x00, 0x03,
				     0x0e, 0xb0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3,
				     0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x10,
				     0x00, 0x00, 0x07, 0x88, 0x07, 0x88, 0x00,
				     0x07, 0x88, 0x07, 0x88, 0x00, 0x00, 0x05,
				     0x00, 0x05, 0x08, 0x11, 0x06, 0x06, 0x01,
				     0x00, 0x00, 0x00, 0x05, 0x08, 0x00, 0x00,
				     0x4a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd5,
				     0x28, 0x28, 0x1e, 0x1e, 0x1f, 0x1f, 0x01,
				     0x01, 0x00, 0x00, 0x24, 0x24, 0x18, 0x18,
				     0x18, 0x18, 0x20, 0x20, 0x18, 0x18, 0x18,
				     0x18, 0x18, 0x18, 0x18, 0x18, 0x2f, 0x2f,
				     0x30, 0x30, 0x31, 0x31);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd6,
				     0x20, 0x20, 0x1e, 0x1e, 0x1f, 0x1f, 0x00,
				     0x00, 0x01, 0x01, 0x24, 0x24, 0x18, 0x18,
				     0x18, 0x18, 0x28, 0x28, 0x18, 0x18, 0x18,
				     0x18, 0x18, 0x18, 0x18, 0x18, 0x2f, 0x2f,
				     0x30, 0x30, 0x31, 0x31);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd8,
				     0xaa, 0xba, 0xaa, 0xaa, 0xaa, 0xba, 0xaa,
				     0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
				     0xaa, 0xaa, 0x00, 0x0a, 0x2a, 0x80, 0x00,
				     0x0a, 0x2a, 0x80, 0x82, 0xca, 0xaa, 0xaa,
				     0x82, 0xca, 0xaa, 0xaa, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
				     0xea, 0xbf, 0xff, 0xff, 0xea, 0xbf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0x08);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x13);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe0,
				     0x1b, 0x24, 0x26, 0x2a, 0x2d, 0x35, 0x25,
				     0x42, 0x06, 0x0b, 0x0f, 0x12, 0x14, 0x12,
				     0x13, 0x13, 0x18, 0x09, 0x16, 0x08, 0x15,
				     0x1b, 0x24, 0x26, 0x2a, 0x2d, 0x35, 0x25,
				     0x42, 0x06, 0x0b, 0x0f, 0x12, 0x14, 0x12,
				     0x13, 0x13, 0x18, 0x09, 0x16, 0x08, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1,
				     0x01, 0x00, 0x08, 0x10, 0x17, 0x1f, 0x26,
				     0x2e, 0x36, 0x3f, 0x46, 0x4e, 0x56, 0x5e,
				     0x66, 0x6e, 0x77, 0x7f, 0x87, 0x8f, 0x98,
				     0xa0, 0xa7, 0xb0, 0xb7, 0xbf, 0xc7, 0xcf,
				     0xd7, 0xde, 0xe6, 0xef, 0xf7, 0xff, 0x03,
				     0xbf, 0x7a, 0xfc, 0x04, 0x33, 0x65, 0xf4,
				     0xc0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1,
				     0x00, 0x07, 0x0f, 0x16, 0x1e, 0x25, 0x2c,
				     0x34, 0x3c, 0x43, 0x4a, 0x52, 0x5a, 0x62,
				     0x69, 0x71, 0x79, 0x81, 0x88, 0x90, 0x99,
				     0xa0, 0xa8, 0xb0, 0xb7, 0xbe, 0xc6, 0xce,
				     0xd5, 0xdc, 0xe4, 0xec, 0xf4, 0x3a, 0x1c,
				     0x7e, 0x8e, 0x4f, 0x20, 0x64, 0x65, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1,
				     0x00, 0x07, 0x0e, 0x15, 0x1c, 0x23, 0x2a,
				     0x31, 0x39, 0x40, 0x47, 0x4e, 0x56, 0x5d,
				     0x65, 0x6c, 0x73, 0x7b, 0x82, 0x8a, 0x91,
				     0x99, 0xa0, 0xa7, 0xaf, 0xb6, 0xbd, 0xc4,
				     0xcc, 0xd3, 0xda, 0xe1, 0xe8, 0x1e, 0xbf,
				     0xbf, 0x61, 0xd8, 0xef, 0xa6, 0x41, 0xc0);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb6, 0x18, 0x18);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int booyi_hx8399b_command_off(struct booyi_hx8399b_command *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 16000, 17000);

	return dsi_ctx.accum_err;
}

static int booyi_hx8399b_command_prepare(struct drm_panel *panel)
{
	struct booyi_hx8399b_command *ctx = to_booyi_hx8399b_command(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(booyi_hx8399b_command_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	booyi_hx8399b_command_reset(ctx);

	ret = booyi_hx8399b_command_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(booyi_hx8399b_command_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int booyi_hx8399b_command_unprepare(struct drm_panel *panel)
{
	struct booyi_hx8399b_command *ctx = to_booyi_hx8399b_command(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = booyi_hx8399b_command_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(booyi_hx8399b_command_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode booyi_hx8399b_command_mode = {
	.clock = (1080 + 90 + 20 + 60) * (1920 + 8 + 2 + 10) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 90,
	.hsync_end = 1080 + 90 + 20,
	.htotal = 1080 + 90 + 20 + 60,
	.vdisplay = 1920,
	.vsync_start = 1920 + 8,
	.vsync_end = 1920 + 8 + 2,
	.vtotal = 1920 + 8 + 2 + 10,
	.width_mm = 62,
	.height_mm = 111,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int booyi_hx8399b_command_get_modes(struct drm_panel *panel,
					   struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &booyi_hx8399b_command_mode);
}

static const struct drm_panel_funcs booyi_hx8399b_command_panel_funcs = {
	.prepare = booyi_hx8399b_command_prepare,
	.unprepare = booyi_hx8399b_command_unprepare,
	.get_modes = booyi_hx8399b_command_get_modes,
};

static int booyi_hx8399b_command_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct booyi_hx8399b_command *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct booyi_hx8399b_command, panel,
				   &booyi_hx8399b_command_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(booyi_hx8399b_command_supplies),
					    booyi_hx8399b_command_supplies,
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

static void booyi_hx8399b_command_remove(struct mipi_dsi_device *dsi)
{
	struct booyi_hx8399b_command *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id booyi_hx8399b_command_of_match[] = {
	{ .compatible = "longcheer,l9360-hx8399b" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, booyi_hx8399b_command_of_match);

static struct mipi_dsi_driver booyi_hx8399b_command_driver = {
	.probe = booyi_hx8399b_command_probe,
	.remove = booyi_hx8399b_command_remove,
	.driver = {
		.name = "panel-booyi-hx8399b-command",
		.of_match_table = booyi_hx8399b_command_of_match,
	},
};
module_mipi_dsi_driver(booyi_hx8399b_command_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for booyi HX8399B 1080p command mode dsi panel");
MODULE_LICENSE("GPL");
