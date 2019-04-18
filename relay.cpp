/*
 * relay.cpp:
 *	App for ElectronBits EBRPIH1118 - Relays 
 *	Copyright (c) 2018-2019
 ***********************************************************************
 *
 *    RpiBase is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 * 
 *    This is a simple example of how the Library can be used for relays,
 *    although there are more features lying in library.
 *
 *    RpiBase is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 ***********************************************************************
 */

#include "RpiBase.h"
#include <ctype.h>
#include <iostream>
#include <string.h>

bool isRelNumber(const char*);
bool isRelCommand(const char*);
int relayCommand(const char*);

using namespace std;

int main(int argc, char** argv){
    if (argc==3
    && isRelNumber(argv[1]) 
    && isRelCommand(argv[2])){
        
        Relays relay = (Relays)initRelays();
        int rel_cmnd  = relayCommand(argv[2]);
        int rel_number = atoi(&argv[1][0]);
        switch(rel_number){
            case 1:
                if(rel_cmnd) relay.energize(&relay.Rel1);
                else relay.denergize(&relay.Rel1);
                break;
            case 2:
                if(rel_cmnd) relay.energize(&relay.Rel2);
                else relay.denergize(&relay.Rel2);
                break;
            case 3:
                if(rel_cmnd) relay.energize(&relay.Rel3);
                else relay.denergize(&relay.Rel3);
                break;
            case 4:
                if(rel_cmnd) relay.energize(&relay.Rel4);
                else relay.denergize(&relay.Rel4);
                break;
            default:
                relaysUsage();
                break;
        }
        return 0;
    }
    else{
        relaysUsage();
        return 0;
    }

}

bool isRelNumber(const char *input_arg){
    if (strlen(input_arg)!=1) return false;
    else {
        if(isdigit(*input_arg)) {
            int rel_number = atoi(&input_arg[0]);
            if (rel_number<1 || rel_number>4) return false;
            else return true;
        }
    }
    return false;
}

bool isRelCommand(const char *input_arg){
    if (strcmp(input_arg,"on")==0 || strcmp(input_arg,"off")==0) return true;
    return false;
}

int relayCommand (const char *input_arg){
    if (strcmp(input_arg,"on")==0){
        return 1;
    }
    return 0;
}