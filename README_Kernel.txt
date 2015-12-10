################################################################################

1. How to Build
	- get Toolchain
		From android git server , codesourcery and etc ..
		
	- edit Makefile
		edit "CROSS_COMPILE" to right toolchain path(You downloaded).
		Ex)  CROSS_COMPILE=/*/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-    // You have to check.

	- make
		$ cd exynos7580
		$ make ARCH=arm64 exynos7580-s5neolte_defconfig
		$ make ARCH=arm64

2. Output files
	- Kernel : arch/arm64/boot/Image
	- module : drivers/*/built-in.o

3. How to Clean	
		$ make ARCH=arm64 clean
		$ make ARCH=arm64 distclean
################################################################################
