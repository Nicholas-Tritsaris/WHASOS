# WHAOS Top-Level Makefile
# Builds init, desktop, and prepares for ISO

.PHONY: all init desktop clean distclean

all: init desktop

init:
	$(MAKE) -C src/init

desktop:
	$(MAKE) -C src/desktop 2>/dev/null || true

iso:
	./scripts/build_iso.sh 1.0

clean:
	$(MAKE) -C src/init clean
	$(MAKE) -C src/desktop clean 2>/dev/null || true
	rm -rf output

distclean: clean
	$(MAKE) -C src/kernel clean 2>/dev/null || true
