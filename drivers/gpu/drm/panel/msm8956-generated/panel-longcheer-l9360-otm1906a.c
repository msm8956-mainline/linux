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

struct truly_otm1906a_command {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data truly_otm1906a_command_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline
struct truly_otm1906a_command *to_truly_otm1906a_command(struct drm_panel *panel)
{
	return container_of(panel, struct truly_otm1906a_command, panel);
}

static void truly_otm1906a_command_reset(struct truly_otm1906a_command *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int truly_otm1906a_command_on(struct truly_otm1906a_command *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x19, 0x06, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x19, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x81);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x83);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x16);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x7e, 0x00, 0x0a, 0x0a, 0x00,
					 0x7e, 0x0a, 0x0a, 0x00, 0x7e, 0x00,
					 0x0a, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x11, 0x11, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x00, 0x00, 0x02, 0x00, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x00, 0x00, 0x00, 0x03, 0x1d,
					 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0,
					 0x00, 0x00, 0x00, 0x00, 0x03, 0x1d,
					 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5,
					 0x0f, 0x05, 0x01, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x81, 0x00, 0x06, 0x8a, 0x82, 0x00,
					 0x06, 0x8a, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x81, 0x04, 0x00, 0x06, 0x8a, 0x82,
					 0x04, 0x00, 0x06, 0x8a, 0x01, 0x03,
					 0x00, 0x06, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x00, 0x02, 0x00, 0x06, 0x8a, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xda);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x33, 0x33, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2,
					 0x80, 0x6c, 0x01, 0x00, 0x0a, 0x80,
					 0x6c, 0x01, 0x00, 0x0a, 0x00, 0x00,
					 0x03, 0x00, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x30, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x81, 0x00, 0x06, 0x8a, 0x82, 0x00,
					 0x06, 0x8a, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x00, 0x00, 0x00, 0x00, 0x81, 0x04,
					 0x00, 0x06, 0x8a, 0x82, 0x04, 0x00,
					 0x06, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x01, 0x03, 0x00, 0x06, 0x8a, 0x00,
					 0x02, 0x00, 0x06, 0x8a, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3,
					 0x33, 0x33, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0x00, 0x30, 0x00,
					 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x40, 0x40, 0x00, 0x00, 0x40, 0x40,
					 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
					 0x00, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x40, 0x40, 0xbf, 0x00, 0x00,
					 0xc0, 0x30, 0xf0, 0x00, 0x00, 0x10,
					 0x00, 0x10, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x10, 0x00, 0x33, 0x00, 0x33, 0x00,
					 0x33, 0x00, 0x77, 0x77, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x11, 0x11, 0x01, 0x01, 0x11, 0x11,
					 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
					 0x01, 0x01, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x01, 0x11, 0x11, 0xff, 0x01, 0x01,
					 0x30, 0x00, 0x03, 0x30, 0x00, 0x01,
					 0x01, 0x01, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x01, 0x01, 0x03, 0x01, 0x03, 0x01,
					 0x03, 0x01, 0x77, 0x77, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb,
					 0x00, 0x00, 0x00, 0xff, 0xf0, 0x0f,
					 0x03, 0x33, 0x33, 0x33, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x08, 0x09, 0x18, 0x19, 0x0c, 0x0d,
					 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x09, 0x08, 0x19, 0x18, 0x0f, 0x0e,
					 0x0d, 0x0c, 0x10, 0x11, 0x12, 0x13);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x14, 0x15, 0x16, 0x17, 0x1c, 0x1d,
					 0x1e, 0x1f, 0x20, 0x07, 0x07, 0x07,
					 0x07, 0x07, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc,
					 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
					 0x07, 0x07);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd,
					 0x16, 0x1a, 0x1a, 0x1a, 0x11, 0x12,
					 0x1a, 0x1a, 0x1a, 0x1a, 0x06, 0x08,
					 0x02, 0x1d, 0x1e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x1f, 0x24, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd,
					 0x16, 0x1a, 0x1a, 0x1a, 0x11, 0x12,
					 0x1a, 0x1a, 0x1a, 0x1a, 0x05, 0x07,
					 0x01, 0x1d, 0x1e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x1f, 0x24, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5,
					 0x44, 0x1e, 0x32, 0x00, 0x88, 0x11,
					 0x23, 0x37, 0x44, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5,
					 0x44, 0x1e, 0x32, 0x00, 0x88, 0x11,
					 0x23, 0x37, 0x44, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0x11, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9,
					 0x00, 0x99, 0x00, 0x99, 0x00, 0x99,
					 0x00, 0x99);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x88);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x36, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3,
					 0x33, 0x04, 0x38, 0x07, 0x80, 0x00,
					 0x20);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe3,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe4,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6,
					 0x01, 0x03, 0x04, 0x08, 0x0b, 0x10,
					 0x1d, 0x27, 0x34, 0x45, 0x52, 0x5f,
					 0x94, 0x89, 0x77, 0x62, 0x49, 0x35,
					 0x2b, 0x28, 0x23, 0x20, 0x13, 0x12);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x35, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x00, 0x00, 0x00);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int truly_otm1906a_command_off(struct truly_otm1906a_command *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 50);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_usleep_range(&dsi_ctx, 16000, 17000);

	return dsi_ctx.accum_err;
}

static int truly_otm1906a_command_prepare(struct drm_panel *panel)
{
	struct truly_otm1906a_command *ctx = to_truly_otm1906a_command(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(truly_otm1906a_command_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	truly_otm1906a_command_reset(ctx);

	ret = truly_otm1906a_command_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(truly_otm1906a_command_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int truly_otm1906a_command_unprepare(struct drm_panel *panel)
{
	struct truly_otm1906a_command *ctx = to_truly_otm1906a_command(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = truly_otm1906a_command_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(truly_otm1906a_command_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode truly_otm1906a_command_mode = {
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

static int truly_otm1906a_command_get_modes(struct drm_panel *panel,
					    struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &truly_otm1906a_command_mode);
}

static const struct drm_panel_funcs truly_otm1906a_command_panel_funcs = {
	.prepare = truly_otm1906a_command_prepare,
	.unprepare = truly_otm1906a_command_unprepare,
	.get_modes = truly_otm1906a_command_get_modes,
};

static int truly_otm1906a_command_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct truly_otm1906a_command *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct truly_otm1906a_command, panel,
				   &truly_otm1906a_command_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(truly_otm1906a_command_supplies),
					    truly_otm1906a_command_supplies,
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
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO_BURST |
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

static void truly_otm1906a_command_remove(struct mipi_dsi_device *dsi)
{
	struct truly_otm1906a_command *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id truly_otm1906a_command_of_match[] = {
	{ .compatible = "longcheer,l9360-otm1906a" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, truly_otm1906a_command_of_match);

static struct mipi_dsi_driver truly_otm1906a_command_driver = {
	.probe = truly_otm1906a_command_probe,
	.remove = truly_otm1906a_command_remove,
	.driver = {
		.name = "panel-truly-otm1906a-command",
		.of_match_table = truly_otm1906a_command_of_match,
	},
};
module_mipi_dsi_driver(truly_otm1906a_command_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for truly OTM1906A 1080p command mode dsi panel");
MODULE_LICENSE("GPL");
