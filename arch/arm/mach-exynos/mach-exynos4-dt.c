/*
 * Samsung's EXYNOS4 flattened device tree enabled machine
 *
 * Copyright (c) 2010-2011 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 * Copyright (c) 2010-2011 Linaro Ltd.
 *		www.linaro.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/kernel.h>
#include <linux/of_platform.h>
#include <linux/of_fdt.h>
#include <linux/serial_core.h>
#include <linux/memblock.h>
#include <linux/clocksource.h>

#include <asm/mach/arch.h>
#include <plat/mfc.h>

#include "common.h"

static void __init exynos4_dt_map_io(void)
{
	exynos_init_io(NULL, 0);
}

static void __init exynos4_dt_machine_init(void)
{
	of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}

static char const *exynos4_dt_compat[] __initdata = {
	"samsung,exynos4210",
	"samsung,exynos4212",
	"samsung,exynos4412",
	NULL
};

static void __init exynos4_reserve(void)
{
#ifdef CONFIG_S5P_DEV_MFC
	struct s5p_mfc_dt_meminfo mfc_mem;

	/* Reserve memory for MFC only if it's available */
	mfc_mem.compatible = "samsung,mfc-v5";
	if (of_scan_flat_dt(s5p_fdt_find_mfc_mem, &mfc_mem))
		s5p_mfc_reserve_mem(mfc_mem.roff, mfc_mem.rsize, mfc_mem.loff,
				mfc_mem.lsize);
#endif
}
DT_MACHINE_START(EXYNOS4210_DT, "Samsung Exynos4 (Flattened Device Tree)")
	/* Maintainer: Thomas Abraham <thomas.abraham@linaro.org> */
	.smp		= smp_ops(exynos_smp_ops),
	.init_irq	= exynos4_init_irq,
	.map_io		= exynos4_dt_map_io,
	.init_early	= exynos_firmware_init,
	.init_machine	= exynos4_dt_machine_init,
	.init_late	= exynos_init_late,
	.init_time	= exynos_init_time,
	.dt_compat	= exynos4_dt_compat,
	.restart        = exynos4_restart,
	.reserve	= exynos4_reserve,
MACHINE_END
