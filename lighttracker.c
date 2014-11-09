 /*
    Light Tracker
    =============

    A very light library to obtain the light sensor info in your OS X device:

    Based on the code found here:
    http://stackoverflow.com/a/18614019/777706

    See the main function in this file to see an example.

    Author: Oriol Nieto (oriol@nyu.edu)
 */

#include "lighttracker.h"
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include <string.h>
#include <stdint.h>
#include <mach/mach.h>

static io_connect_t dataPort = 0;

typedef struct {
    uint64_t values[2];
} lightData;

lightData myLightData;

int init_light()
{
    kern_return_t result;
    mach_port_t masterPort;

    result = IOMasterPort(MACH_PORT_NULL, &masterPort);

    io_service_t serviceObject = IOServiceGetMatchingService(kIOMasterPortDefault, 
            IOServiceMatching("AppleLMUController"));
    if (!serviceObject) {
        fprintf(stderr, "failed to find ambient light sensors\n");
        exit(1);
    }

    kern_return_t kr = IOServiceOpen(serviceObject, mach_task_self(), 0, &dataPort);
    if (kr != KERN_SUCCESS) {
        mach_error("IOServiceOpen:", kr);
        exit(kr);
    }
    IOObjectRelease(serviceObject);

    return 1;
}

int get_light_value() {
    uint32_t outputs = 2;

    kern_return_t kr = IOConnectCallMethod(dataPort, 0, nil, 0, nil, 0,
            myLightData.values, &outputs, nil, 0);
    if (kr != KERN_SUCCESS) {
        mach_error("IOConnectCallMethod: ", kr);
        exit(kr);
    }

    return myLightData.values[0];
}

//int main() {
//    init_light();
//    printf("%d\n", get_light_value());
//    return 0;
//}
