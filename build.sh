#!/bin/bash
# Simple script to Build the MC Code
rm -rf main *.o
gcc -c -g -I/uufs/chpc.utah.edu/sys/installdir/gsl/2.3-c7/include main.c
gcc -o main main.o -g -Wl,-rpath=/uufs/chpc.utah.edu/sys/installdir/gsl/2.3-c7/lib \
       -L/uufs/chpc.utah.edu/sys/installdir/gsl/2.3-c7/lib -lgslcblas -lgsl -lm
rm -rf *.o
