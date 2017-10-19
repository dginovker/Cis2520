.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

INCLUDES = -linclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/
LIBDIR = lib/

SOURCE = $(SRCDIR)LinkedListAPI.c $(SRCDIR)Stack.c $(SRCDIR)Test.c $(SRCDIR)intListTest.c $(SRCDIR)stackTest.c $(SRCDIR)intStackFunctions.c
PROGNAME = $(BINDIR)main.out

default: compile

ranlib:
>ranlib $(LIBDIR)*

test:
>$(CC) $(CFLAGS) $(SRCDIR)testMain.c $(SOURCE) -o $(BINDIR)testMain.out

compile:
>$(CC) $(CFLAGS) $(SRCDIR)main.c $(SOURCE) -o $(PROGNAME)
