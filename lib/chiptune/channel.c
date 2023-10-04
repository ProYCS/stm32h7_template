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
        case WAVE_SQUARE:
            if(channel->run == 1)
            {
                channel->scale_count += (double)1 / SAMPLE_RATE;
                if(channel->scale_count > channel->scale)
                {
                    channel->scale_count = 0;
                }
                channel->time_count += (double)1 / SAMPLE_RATE;
                if(channel->time_count > channel->time)
                {
                    channel->run = 0;
                    square_finish(channel);
                }

                square_step(channel);
            }
            break;
        case WAVE_TRIANGLE:
             if(channel->run == 1)
            {
                channel->scale_count += (double)1 / SAMPLE_RATE;
                if(channel->scale_count > channel->scale)
                {
                    channel->scale_count = 0;
                }
                channel->time_count += (double)1 / SAMPLE_RATE;
                if(channel->time_count > channel->time)
                {
                    channel->run = 0;
                    triangle_finish(channel);
                }

                triangle_step(channel);
            }
            break;
    }
}

void channel_play(CHANNEL *channel,int type,double freq,double time,int amp,double parameter1,double parameter2,double parameter3,double parameter4)
{
    channel->type = type;
    channel->time = time;
    channel->freq = freq;
    channel->parameter1 = parameter1;
    channel->parameter2 = parameter2;
    channel->parameter3 = parameter3;
    channel->parameter4 = parameter4;
    channel->scale = (double)1 / channel->freq;
    channel->wave_amp = amp;
    channel->time_count = 0;
    channel->scale_count = 0;
    channel->run = 1;
    switch(type)
    {
        case WAVE_SQUARE:
            square_init(channel);
            break;
        case WAVE_TRIANGLE:
            triangle_init(channel);
            break;
    }

}
