/*
 * RpiBase.cpp:
 *	Library for ElectronBits EBRPIH1118 
 *	Copyright (c) 2018-2019
 ***********************************************************************
 *
 *    RpiBase is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RpiBase is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 ***********************************************************************
 */

#include "RpiBase.h"


Relays initRelays(void){
    wiringPiSetup();
    Relays relay;
    relay.init();
    // relay.printStat();
    
    return relay;
}

void Relays::init(void){
    Rel1.pin_num = REL1;
    Rel1.state = OFF;
    Rel1.id = 1;
    Rel2.pin_num = REL2;
    Rel2.state = OFF;
    Rel2.id = 2;
    Rel3.pin_num = REL3;
    Rel3.state = OFF;
    Rel3.id = 3;
    Rel4.pin_num = REL4;
    Rel3.state = OFF;
    Rel4.id = 4;
    pinMode(Rel1.pin_num,OUTPUT);
    pinMode(Rel2.pin_num,OUTPUT);
    pinMode(Rel3.pin_num,OUTPUT);
    pinMode(Rel4.pin_num,OUTPUT);
}

void Relays::printStat(void){
    printf(
    "    Rel1 bound to: pin# %d\tState: %s\n\
    Rel2 bound to: pin# %d\tState: %s\n\
    Rel3 bound to: pin# %d\tState: %s\n\
    Rel4 bound to: pin# %d\tState: %s\n",\
    Rel1.pin_num,Rel1.state?"On":"Off"\
    ,Rel2.pin_num,Rel2.state?"On":"Off"\
    ,Rel3.pin_num,Rel3.state?"On":"Off"\
    ,Rel4.pin_num,Rel4.state?"On":"Off");
    
}

void Relays::energize(Relay *rel_num){
    digitalWrite(rel_num->pin_num,HIGH);
    rel_num->state = ON;
    #if DEBUG
        printf("Relay#%d will be: %s\n",rel_num->id,rel_num->state ? "On":"Off");
    #endif
}

void Relays::denergize(Relay *rel_num){
    digitalWrite(rel_num->pin_num,LOW);
    rel_num->state = OFF;
    #if DEBUG
        printf("Relay#%d will be: %s\n",rel_num->id,rel_num->state ? "On":"Off");
    #endif 
}

void relaysUsage(void){
    printf("Usage: ./relay [relay number:1/2/3/4] [state:on/off]\n\
    e.g. ./relay 1 on\n\
    will trun on the relay number 1.\n");
}