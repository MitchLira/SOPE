CC = gcc
CFLAGS  = -Wall

OBJECTS = rmdup.o lsdir.o 


all: rmdup lsdir

rmdup:    rmdup.o
	  cc bin/rmdup.o -o bin/rmdup $(CFLAGS)
	  
lsdir:    lsdir.o
	  cc bin/lsdir.o -o bin/lsdir $(CFLAGS)
	  
lsdir.o:  lsdir.c
	  cc -c lsdir.c -o bin/lsdir.o $(CFLAGS)

rmdup.o:  rmdup.c
	  cc -c rmdup.c -o bin/rmdup.o $(CFLAGS)
