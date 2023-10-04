#ifndef _CHANNEL_H
#define _CHANNEL_H

#define CHANNEL_NUM 4

#define SAMPLE_RATE 100000

#define WAVE_SQUARE     1
#define WAVE_TRIANGLE   2


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


    double parameter1;
    double parameter2;
    double parameter3;
    double parameter4;
} CHANNEL;

extern CHANNEL channel1;
extern CHANNEL channel2;
extern CHANNEL channel3;
extern CHANNEL channel4;

void channel_step(CHANNEL *channel);
void channel_play(CHANNEL *channel,int type,double freq,double time,int amp,double parameter1,double parameter2,double parameter3,double parameter4);

#endif
