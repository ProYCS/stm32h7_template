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
        case WAVE_SQUARE:channel->scale_count += (double)1 / SAMPLE_RATE;
                         if(channel->scale_count > channel->scale)
                         {
                                channel->scale_count = 0;
                         }
                         channel->time_count += (double)1 / SAMPLE_RATE;
                         if(channel->time_count > channel->time)
                         {
                                channel->run = 0;
                         }

                         if(channel->scale_count > channel->scale / 2)
                         {
                                channel->wave = channel->wave_amp;
                         }
                         else
                         {
                                channel->wave = 0;
                         }
                         break;
        case WAVE_TRAINGLE:break;
    }
}

void channel_play(CHANNEL *channel,int type,double freq,double time)
{
    channel->type = type;
    channel->time = time;
    channel->scale = channel->freq / SAMPLE_RATE;
    channel->time_count = 0;
    channel->scale_count = 0;
    channel->run = 1;
}
