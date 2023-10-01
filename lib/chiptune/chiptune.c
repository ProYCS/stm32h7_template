#include"chiptune.h"
#include"channel.h"
#include"dac.h"

void chiptune_init(void)
{

}


/*user port*/
void chiptune_audio(unsigned int amp)
{
    dac_set(amp);
}

void chiptune_tick(void)
{
    channel_step(&channel1);
    chiptune_audio(channel1.wave);
}

