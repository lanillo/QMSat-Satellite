#include "em_device.h"
#include "em_chip.h"

#include "Factory.hpp"

enum {
  A,
  B,
  C,
  D,
  E
};

#define LED_PORT E
#define BUTTON_PORT B
#define LED0 2
#define LED1 3

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  CMU->HFPERCLKEN0 = (1 << 13); // Enable GPIO clock

  Factory factory = Factory();
  StateManager* stateManager = factory.createStateManager();

  GPIO->P[LED_PORT].MODEL = (5 << 12) | (4 << 8);
  GPIO->P[LED_PORT].DOUTSET = 1 << LED0;
  /* Infinite loop */
  while (true)
  {
	  stateManager->execute();
  }
}
