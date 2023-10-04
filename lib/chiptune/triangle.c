#include"triangle.h"

void triangle_init(CHANNEL *channel)
{
    channel->wave = 0;
}

void triangle_step(CHANNEL *channel)
{
    if(channel->scale_count < channel->scale * 0.5)
    {
        channel->wave += channel->wave_amp / (channel->scale * 0.5 / ((double)1 / SAMPLE_RATE));
    }
    else
    {
        channel->wave -= channel->wave_amp / (channel->scale * 0.5 / ((double)1 / SAMPLE_RATE));
    }
}

void triangle_finish(CHANNEL *channel)
{
    channel->wave = 0;
}
