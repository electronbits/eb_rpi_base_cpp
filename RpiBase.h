/*
 * RpiBase.h:
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

#ifndef RPIBASE_H_
#define RPIBASE_H_

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

/*
Mapping pins of rpi
*/
#define REL1 0
#define REL2 2
#define REL3 26
#define REL4 24

#define DEBUG 0

typedef enum RelayState {
    OFF,
    ON
}RelayState;

typedef struct Relay {
    int pin_num;
    int id;
    RelayState state;
}Relay;

typedef struct {
    Relay Rel1;
    Relay Rel2;
    Relay Rel3;
    Relay Rel4;
    void init(void);
    void printStat(void);
    void energize(Relay*);
    void denergize(Relay*);
}Relays;

extern Relays initRelays(void);
extern void relaysUsage(void);

#endif