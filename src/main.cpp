
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "Timer.h"
#include "BlinkLed.h"


namespace
{
  // ----- Timing definitions -------------------------------------------------

  // Keep the LED on for 2/3 of a second.
  constexpr Timer::ticks_t BLINK_ON_TICKS = Timer::FREQUENCY_HZ * 3 / 4;
  constexpr Timer::ticks_t BLINK_OFF_TICKS = Timer::FREQUENCY_HZ
      - BLINK_ON_TICKS;
}


int
main(int argc, char* argv[])
{
  // Send a greeting to the trace device (skipped on Release).
  //trace_puts("Hello ARM World!");

  // At this stage the system clock should have already been configured
  // at high speed.
  //trace_printf("System clock: %u Hz\n", SystemCoreClock);

  Timer timer;
  timer.start();

  BlinkLed blinkLed;

  // Perform all necessary initialisations for the LED.
  blinkLed.powerUp();

  uint32_t seconds = 0;

  // Infinite loop
  while (1)
    {
      blinkLed.turnOn();
      timer.sleep(seconds== 0 ? Timer::FREQUENCY_HZ : BLINK_ON_TICKS);

      blinkLed.turnOff();
      timer.sleep(BLINK_OFF_TICKS);

      ++seconds;

      // Count seconds on the trace device.
      trace_printf("Second %u\n", seconds);
    }
  // Infinite loop, never return.
}

