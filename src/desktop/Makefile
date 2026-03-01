# WHAOS Panel / Desktop components
# Requires: GTK3, pkg-config

CC = gcc
CFLAGS = -Wall -O2 $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

TARGET = whaos-panel

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.c whaos_panel.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
