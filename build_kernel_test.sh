#!/bin/bash

export ARCH=arm64
export CROSS_COMPILE=/opt/toolchains/aarch64-linux-android-4.8/bin/aarch64-linux-android-

make ARCH=arm64 exynos7580-s5neolte_defconfig
make ARCH=arm64