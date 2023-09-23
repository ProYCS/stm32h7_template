#ifndef _CHIPTUNE_H
#define _CHIPTUNE_H

#include "stm32h7xx_hal.h"

void chiptune_init(void);
void chiptune_audio(unsigned int amp);
void chiptune_tick(void);

#endif
