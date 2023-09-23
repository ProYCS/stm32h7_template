#ifndef _CHANNEL_H
#define _CHANNEL_H

#define CHANNEL_NUM 4

#define WAVE_SQUARE     1
#define WAVE_TRAINGLE   2


typedef struct {
    int type;
    double freq;

    unsigned int wave_amp;
    double time;
    double time_count;
    int run;

    int parameter1;
    int parameter2;
    int parameter3;
    int parameter4;
} CHANNEL;

void channel_step(CHANNEL *channel);
void channel_play(CHANNEL *channel,int type,double freq,double time);

#endif
