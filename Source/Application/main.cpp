#include "em_device.h"
#include "em_chip.h"
#include "efm32gg990f1024.h"

#include "Factory.hpp"

int main(void)
{
  /* Chip errata */

  CMU->HFPERCLKEN0 = (1 << 13) | (1 << 5); // Enable GPIO and Timer0 peripheral clocks

  Factory factory = Factory();
  StateManager* stateManager = factory.createStateManager();

  /* Infinite loop */
  while (true)
  {
	  stateManager->execute();
  }
}
