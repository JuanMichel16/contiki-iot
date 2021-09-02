#include "contiki.h"
#include "sys/etimer.h"
#include <stdio.h>
#include "virtual_sensor.h"

PROCESS(sensor_node, "Sensor reading node");
AUTOSTART_PROCESSES(&sensor_node);

static struct etimer timer;

PROCESS_THREAD(sensor_node, ev, data)

{
    PROCESS_BEGIN();

        etimer_set(&timer, 5 * CLOCK_SECOND);

        while(1) {

            PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
            
            float temperature_reading = read_temperature();
            float humidity_reading = read_humidity();

            printf("Temperature reading: %.2f C\n", temperature_reading);
            printf("Humidity: %.2f %%\n", humidity_reading);


            etimer_reset(&timer);
        }

    PROCESS_END();
}