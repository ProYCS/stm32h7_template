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
        case WAVE_SQUARE:if(channel->run == 1)
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
                            }

                            if(channel->scale_count > channel->scale / 2)
                            {
                                channel->wave = channel->wave_amp;
                                HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_SET);
                            }
                            else
                            {
                                channel->wave = 0;
                                HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,GPIO_PIN_RESET);
                            }
                         }
                         break;
        case WAVE_TRAINGLE:break;
    }
}

void channel_play(CHANNEL *channel,int type,double freq,double time,int amp)
{
    channel->type = type;
    channel->time = time;
    channel->freq = freq;
    channel->scale = (double)1 / channel->freq;
    channel->wave_amp = amp;
    channel->time_count = 0;
    channel->scale_count = 0;
    channel->run = 1;
}
