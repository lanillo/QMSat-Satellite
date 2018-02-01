#include "em_device.h"
#include "em_chip.h"

#include "Factory.hpp"

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  Factory factory = Factory();
  StateManager* stateManager = factory.createStateManager();

  /* Infinite loop */
  while (true)
  {
	  stateManager->execute();
  }
}
