#include"square.h"

void square_init(CHANNEL *channel)
{
    channel->wave = 0;
}

void square_step(CHANNEL *channel)
{
    if(channel->scale_count > channel->scale * channel->parameter1)
    {
        channel->wave = channel->wave_amp;
    }
    else
    {
        channel->wave = 0;
    }
}

void square_finish(CHANNEL *channel)
{
    channel->wave = 0;
}
