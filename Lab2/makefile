.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

INCLUDES = -linclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/

OTHERSOURCES = $(SRCDIR)
OTHEROBJS = $(OBJDIR)

SOURCE = $(SRCDIR)Book.c $(SRCDIR)boardgame.c $(SRCDIR)store.c
OBJS = $(OBJDIR)Book.o $(OBJDIR)boardgame.o $(OBJDIR)store.o
PROGNAME = $(BINDIR)main.out

default: link

test:
>$(CC) $(CFLAGS) -c $(SRCDIR)testMain.c $(SOURCE)
>mv *.o $(OBJDIR)
>$(CC) $(OBJS) $(OBJDIR)testMain.o -o $(BINDIR)testMain.out

link: compile
>$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

compile:
>$(CC) $(CFLAGS) -c $(SRCDIR)main.c $(SOURCE)
>mv *.o $(OBJDIR)

clean:
>rm obj/*
>rm bin/*
