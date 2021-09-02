CONTIKI_PROJECT = sensor-node
all: $(CONTIKI_PROJECT)

PROJECT_SOURCEFILES += virtual_sensor.c

CONTIKI= ../..
include $(CONTIKI)/Makefile.include