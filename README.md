lighttracker
============

A little (very little) library in C to obtain the Light Sensor information of your OS X

Usage
-----

Uncomment the main function in `lighttracker.c` to see the library in motion.

Compilation with the main function uncommented:
    clang -o lighttracker lighttracker.c -framework IOKit -framework CoreFoundation
