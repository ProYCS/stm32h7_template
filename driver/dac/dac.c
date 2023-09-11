/*
Copyright (C) 2023 All rights reserved.

This program is free software you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation either version 2 of the License, or (at your option) any 
later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY without 
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

See the GNU General Public License for more details.

*/

#include "dac.h"

DAC_HandleTypeDef dac1;

void dac_init(void)
{
    DAC_ChannelConfTypeDef dac_config;
    dac_config.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
    dac_config.DAC_Trigger = DAC_TRIGGER_T6_TRGO;
    dac_config.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
    dac_config.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_DISABLE;
    dac_config.DAC_UserTrimming = DAC_TRIMMING_FACTORY;

    dac1.Instance = DAC1;
}
