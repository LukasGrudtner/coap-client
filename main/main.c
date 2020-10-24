#include "uart.c"
#include "coap.c"

static void start_listening(void *arg) {
    setup_coap();
    setup_uart();
    listen_uart(arg, coap_example_client);
    vTaskDelete(NULL);
}

void app_main(void) {
    xTaskCreate(start_listening, "coap", 8 * 1024, NULL, 5, NULL);
}
