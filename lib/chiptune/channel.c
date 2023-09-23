#include"channel.h"
#include"square.h"

CHANNEL channel1;
CHANNEL channel2;
CHANNEL channel3;
CHANNEL channel4;

void channel_step(CHANNEL *channel)
{
    switch(channel->type)
    {
        case WAVE_SQUARE:break;
        case WAVE_TRAINGLE:break;
    }
}

void channel_play(CHANNEL *channel,int type,double freq,double time)
{
    channel->type = type;
    channel->time = time;
    channel->run = 1;
}
