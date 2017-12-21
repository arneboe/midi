#define STM32F1 //opencm3 chooses headers according to this

#include <stdio.h>
#include <stdlib.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>



static void gpio_setup()
{
  /* Enable GPIOA clock. */
  /* Manually: */
  // RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;
  /* Using API functions: */
  rcc_periph_clock_enable(RCC_GPIOC);

  gpio_set_mode((unsigned long)GPIOC, GPIO_MODE_OUTPUT_50_MHZ,
          GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
}

int main (int argc, char* argv[])
{
  //FIXME what is hse 8 mhz?
  rcc_clock_setup_in_hse_8mhz_out_72mhz();
  gpio_setup();

  while (1)
  {
    gpio_toggle((unsigned long)GPIOC, GPIO13);
    for (int i = 0; i < 800000; i++)  /* Wait a bit. */
      __asm__("nop");
  }
  return 0;
}

