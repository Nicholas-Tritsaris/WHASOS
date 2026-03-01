# WHAOS Kernel Build (Linux-based)
# If using stock Linux kernel, this fetches/configures/builds it

KERNEL_VERSION ?= 6.6
KERNEL_SRC ?= linux-$(KERNEL_VERSION)
KERNEL_URL = https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-$(KERNEL_VERSION).tar.xz

ARCH = x86_64
CROSS_COMPILE ?=

.PHONY: all config build install clean

all: build

fetch:
	@echo "Fetching Linux kernel $(KERNEL_VERSION)..."
	wget -c $(KERNEL_URL)
	tar xf linux-$(KERNEL_VERSION).tar.xz

config: $(KERNEL_SRC)
	cp whaos_defconfig $(KERNEL_SRC)/.config
	$(MAKE) -C $(KERNEL_SRC) ARCH=$(ARCH) olddefconfig

build: config
	$(MAKE) -C $(KERNEL_SRC) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -j$$(nproc)
	cp $(KERNEL_SRC)/arch/x86/boot/bzImage ../output/vmlinuz-whacos

install: build
	$(MAKE) -C $(KERNEL_SRC) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules_install
	cp ../output/vmlinuz-whacos /boot/vmlinuz-whacos

clean:
	rm -rf $(KERNEL_SRC) linux-$(KERNEL_VERSION).tar.xz
	rm -f ../output/vmlinuz-whacos
