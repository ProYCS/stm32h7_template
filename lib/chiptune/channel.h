#ifndef _CHANNEL_H
#define _CHANNEL_H

#define CHANNEL_NUM 4

#define SAMPLE_RATE 100000

#define WAVE_SQUARE     1
#define WAVE_TRAINGLE   2


typedef struct {
    int type;
    double freq;

    double wave_amp;
    double wave;
    double time;
    double time_count;
    double scale;
    double scale_count;
    int run;


    int parameter1;
    int parameter2;
    int parameter3;
    int parameter4;
} CHANNEL;

void channel_step(CHANNEL *channel);
void channel_play(CHANNEL *channel,int type,double freq,double time);

#endif
