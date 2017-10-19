.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

INCLUDES = -linclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/
LIBDIR = lib/

SOURCE = $(SRCDIR)car.c $(SRCDIR)intListTest.c $(SRCDIR)LinkedListAPI.c $(SRCDIR)readCars.c $(SRCDIR)simulation.c $(SRCDIR)Test.c
PROGNAME = $(BINDIR)main.out

default: compile

ranlib:
>ranlib $(LIBDIR)*

test:
>$(CC) $(CFLAGS) $(SRCDIR)testMain.c $(SOURCE) -o $(BINDIR)testMain.out

compile:
>$(CC) $(CFLAGS) $(SRCDIR)main.c $(SOURCE) -o $(PROGNAME)
