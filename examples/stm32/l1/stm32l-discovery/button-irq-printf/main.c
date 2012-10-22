/*
 * Karl Palsson, 2012 <karlp@tweak.net.au
 */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/l1/rcc.h>
#include <libopencm3/stm32/l1/gpio.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/usart.h>

#include "syscfg.h"

static struct state_t state;

void clock_setup(void) {
    /* Lots of things on all ports... */
    rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOAEN);
    rcc_peripheral_enable_clock(&RCC_AHBENR, RCC_AHBENR_GPIOBEN);

    /* Enable clocks for USART2. */
    rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
}

void gpio_setup(void) {
    gpio_mode_setup(LED_DISCO_GREEN_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_DISCO_GREEN_PIN);

    /* Setup GPIO pins for USART2 transmit. */
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

    /* Setup USART2 TX pin as alternate function. */
    gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

void usart_setup(void) {
    usart_set_baudrate(USART_CONSOLE, 115200);
    usart_set_databits(USART_CONSOLE, 8);
    usart_set_stopbits(USART_CONSOLE, USART_STOPBITS_1);
    usart_set_mode(USART_CONSOLE, USART_MODE_TX);
    usart_set_parity(USART_CONSOLE, USART_PARITY_NONE);
    usart_set_flow_control(USART_CONSOLE, USART_FLOWCONTROL_NONE);

    /* Finally enable the USART. */
    usart_enable(USART_CONSOLE);
}

/**
 * Use USART_CONSOLE as a console.
 * @param file
 * @param ptr
 * @param len
 * @return
 */
int _write(int file, char *ptr, int len) {
    int i;

    if (file == STDOUT_FILENO || file == STDERR_FILENO) {
        for (i = 0; i < len; i++) {
            if (ptr[i] == '\n') {
                usart_send_blocking(USART_CONSOLE, '\r');
            }
            usart_send_blocking(USART_CONSOLE, ptr[i]);
        }
        return i;
    }
    errno = EIO;
    return -1;
}

void BUTTON_DISCO_USER_isr(void) {
    exti_reset_request(BUTTON_DISCO_USER_EXTI);
    if (state.falling) {
        state.falling = false;
        exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_RISING);
        //        ILOG("fell: %d\n", TIM_CNT(TIM7));
        puts("fell!\n");
    } else {
        puts("Rose!\n");
        //        TIM_CNT(TIM7) = 0;
        state.falling = true;
        exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_FALLING);
    }
}

void setup_buttons(void) {
    /* Enable EXTI0 interrupt. */
    nvic_enable_irq(BUTTON_DISCO_USER_NVIC);

    gpio_mode_setup(BUTTON_DISCO_USER_PORT, GPIO_MODE_INPUT, GPIO_PUPD_NONE, BUTTON_DISCO_USER_PIN);

    /* Configure the EXTI subsystem. */
    exti_select_source(BUTTON_DISCO_USER_EXTI, BUTTON_DISCO_USER_PORT);
    state.falling = false;
    exti_set_trigger(BUTTON_DISCO_USER_EXTI, EXTI_TRIGGER_RISING);
    exti_enable_request(BUTTON_DISCO_USER_EXTI);
}

int main(void) {
    int i;
    int j = 0;
    clock_setup();
    gpio_setup();
    usart_setup();
    puts("hi guys!\n");
    setup_buttons();
    while (1) {
        puts("tick:");
        putchar('a' + (j++ % 26));
        gpio_toggle(GPIOB, GPIO7); /* LED on/off */
        for (i = 0; i < 100000; i++) /* Wait a bit. */
            __asm__("NOP");
    }

    return 0;
}
