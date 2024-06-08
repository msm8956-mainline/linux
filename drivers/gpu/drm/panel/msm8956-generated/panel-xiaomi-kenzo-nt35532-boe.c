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

struct boe_nt35532 {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct regulator_bulk_data *supplies;
	struct gpio_desc *reset_gpio;
};

static const struct regulator_bulk_data boe_nt35532_supplies[] = {
	{ .supply = "vsn" },
	{ .supply = "vsp" },
};

static inline struct boe_nt35532 *to_boe_nt35532(struct drm_panel *panel)
{
	return container_of(panel, struct boe_nt35532, panel);
}

static void boe_nt35532_reset(struct boe_nt35532 *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int boe_nt35532_on(struct boe_nt35532 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0xee);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x18, 0x40);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x18, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x68, 0x13);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x75, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x76, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x77, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x78, 0x22);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x79, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7a, 0x51);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7b, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7c, 0x73);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7d, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7e, 0x8d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7f, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x80, 0xa4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x81, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x82, 0xb8);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x83, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x84, 0xca);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x85, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x86, 0xd9);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x87, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x88, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x89, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8a, 0x36);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8b, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8c, 0x75);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8d, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8e, 0xa7);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8f, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x90, 0xf2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x91, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x92, 0x2b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x93, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x94, 0x2b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x95, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x96, 0x61);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x97, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x98, 0x9d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x99, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9a, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9b, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9c, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9d, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9e, 0x27);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9f, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa0, 0x63);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa2, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa3, 0x6b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa4, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5, 0x72);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa6, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa7, 0x7e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xaa, 0x87);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xab, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xac, 0x93);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xad, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xae, 0x9b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xaf, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0xa2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0x22);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0x51);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x73);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x8d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0xa4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbf, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0xb8);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0xca);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0xd9);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0x36);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0x75);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0xa7);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0xf2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0, 0x2b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2, 0x2b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0x61);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x9d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd7, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0xc6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xda, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdb, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdc, 0x27);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdd, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xde, 0x63);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdf, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe0, 0x6b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2, 0x72);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe3, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe4, 0x7e);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6, 0x87);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe7, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe8, 0x93);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xea, 0x9b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xeb, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xec, 0xa2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xed, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xee, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xef, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf0, 0xd6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf1, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf2, 0xdd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf4, 0xea);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf6, 0xf7);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf7, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf8, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf9, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfa, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x01, 0x17);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x02, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x03, 0x21);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x04, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x05, 0x2a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x06, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x07, 0x4b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x08, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x09, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0a, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0b, 0x98);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0c, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0d, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0e, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x0f, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x10, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x11, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x12, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x13, 0x35);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x14, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x15, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x16, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x17, 0xa4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x18, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x19, 0xcc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1a, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1b, 0x07);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1c, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1d, 0x2f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1e, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1f, 0x6a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x20, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x21, 0x71);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x22, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x23, 0x85);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x24, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x25, 0x9a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x26, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x27, 0xb2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x28, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x29, 0xca);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2a, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2b, 0xe2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2d, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x2f, 0xf5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x30, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x31, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x32, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x33, 0xd6);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x34, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x35, 0xdd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x36, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x37, 0xea);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x38, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x39, 0xf7);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x3a, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x3b, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x3d, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x3f, 0x0d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x40, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x41, 0x17);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x42, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x43, 0x21);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x44, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x45, 0x2a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x46, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x47, 0x4b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x48, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x49, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4a, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4b, 0x98);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4c, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4d, 0xc0);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4e, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x4f, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x50, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x51, 0x34);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x52, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x53, 0x35);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x54, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x55, 0x68);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x56, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x58, 0xa4);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x59, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5a, 0xcc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5b, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5c, 0x07);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5d, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5e, 0x2f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x5f, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x60, 0x6a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x61, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x62, 0x71);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x63, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x64, 0x85);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x65, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x66, 0x9a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x67, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x68, 0xb2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x69, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6a, 0xca);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6b, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6c, 0xe2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6d, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6e, 0xf5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6f, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x70, 0xff);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x71, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x72, 0xcd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x73, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x74, 0xd5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x75, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x76, 0xe3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x77, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x78, 0xef);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x79, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7a, 0xfb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7b, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7c, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7d, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7e, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x7f, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x80, 0x1b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x81, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x82, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x83, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x84, 0x46);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x85, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x86, 0x63);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x87, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x88, 0x94);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x89, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8a, 0xbb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8b, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8c, 0xfc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8d, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8e, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x8f, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x90, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x91, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x92, 0x66);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x93, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x94, 0xa3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x95, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x96, 0xcc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x97, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x98, 0x0b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x99, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9a, 0x38);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9b, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9c, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9d, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9e, 0x97);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x9f, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa0, 0x97);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa2, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa3, 0x99);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa4, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5, 0x9b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa6, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa7, 0x9d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xaa, 0x9f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xab, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xac, 0xa1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xad, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xae, 0xa2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xaf, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb0, 0xcd);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb1, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb2, 0xd5);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb4, 0xe3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb5, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb6, 0xef);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb7, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb8, 0xfb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb9, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xba, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbc, 0x11);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbd, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbe, 0x1b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xbf, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x46);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x63);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc6, 0x94);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc7, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc8, 0xbb);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc9, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xca, 0xfc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x32);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd0, 0x66);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd1, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd2, 0xa3);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3, 0x02);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0xcc);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd5, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd6, 0x0b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd7, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0x38);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xda, 0x8a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdb, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdc, 0x97);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdd, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xde, 0x97);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xdf, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe0, 0x99);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2, 0x9b);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe3, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe4, 0x9d);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe5, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe6, 0x9f);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe7, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe8, 0xa1);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe9, 0x03);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xea, 0xa2);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x36, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x35, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x6e, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x04);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x08, 0x06);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x53, 0x24);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x55, 0x00);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd3, 0x0a);
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd4, 0x0a);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int boe_nt35532_off(struct boe_nt35532 *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 150);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 150);

	return dsi_ctx.accum_err;
}

static int boe_nt35532_prepare(struct drm_panel *panel)
{
	struct boe_nt35532 *ctx = to_boe_nt35532(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = regulator_bulk_enable(ARRAY_SIZE(boe_nt35532_supplies), ctx->supplies);
	if (ret < 0) {
		dev_err(dev, "Failed to enable regulators: %d\n", ret);
		return ret;
	}

	boe_nt35532_reset(ctx);

	ret = boe_nt35532_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(boe_nt35532_supplies), ctx->supplies);
		return ret;
	}

	return 0;
}

static int boe_nt35532_unprepare(struct drm_panel *panel)
{
	struct boe_nt35532 *ctx = to_boe_nt35532(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = boe_nt35532_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(boe_nt35532_supplies), ctx->supplies);

	return 0;
}

static const struct drm_display_mode boe_nt35532_mode = {
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

static int boe_nt35532_get_modes(struct drm_panel *panel,
				 struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &boe_nt35532_mode);
}

static const struct drm_panel_funcs boe_nt35532_panel_funcs = {
	.prepare = boe_nt35532_prepare,
	.unprepare = boe_nt35532_unprepare,
	.get_modes = boe_nt35532_get_modes,
};

static int boe_nt35532_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct boe_nt35532 *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct boe_nt35532, panel,
				   &boe_nt35532_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ret = devm_regulator_bulk_get_const(dev,
					    ARRAY_SIZE(boe_nt35532_supplies),
					    boe_nt35532_supplies,
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

static void boe_nt35532_remove(struct mipi_dsi_device *dsi)
{
	struct boe_nt35532 *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id boe_nt35532_of_match[] = {
	{ .compatible = "xiaomi,kenzo-nt35532-boe" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, boe_nt35532_of_match);

static struct mipi_dsi_driver boe_nt35532_driver = {
	.probe = boe_nt35532_probe,
	.remove = boe_nt35532_remove,
	.driver = {
		.name = "panel-boe-nt35532",
		.of_match_table = boe_nt35532_of_match,
	},
};
module_mipi_dsi_driver(boe_nt35532_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for boe nt35532 1080p video mode dsi panel");
MODULE_LICENSE("GPL");
