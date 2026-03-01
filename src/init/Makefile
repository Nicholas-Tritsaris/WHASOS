# WHAOS Daemon Manager (whad) - init process
# Builds standalone binary for PID 1

CC = gcc
CFLAGS = -Wall -O2 -static
TARGET = whad

.PHONY: all clean

all: $(TARGET)

$(TARGET): whad.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
