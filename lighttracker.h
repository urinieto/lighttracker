/*
   Light Tracker
   =============

   A very light library to obtain the light sensor info in your OS X device:

   Based on the code found here:
http://stackoverflow.com/a/18614019/777706

See the main function in the lighttracker.c file to see an example.

Author: Oriol Nieto (oriol@nyu.edu)
*/
#ifndef LIGHTTRACKER_H
#define LIGHTTRACKER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    int init_light();
    int get_light_value();

#ifdef __cplusplus
}
#endif

#endif

