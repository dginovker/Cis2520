.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

INCLUDES = -linclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/
LIBDIR = lib/

OTHERSOURCES = $(SRCDIR)
OTHEROBJS = $(OBJDIR)
LIBS = libLinkedList

SOURCE = $(SRCDIR)Book.c $(SRCDIR)intListTest.c $(SRCDIR)Test.c $(SRCDIR)BookListTest.c
PROGNAME = $(BINDIR)main.out

default: compile

ranlib:
>ranlib $(LIBDIR)libLinkedList.a

test:
>$(CC) $(CFLAGS) $(SRCDIR)testMain.c $(SOURCE) -L$(LIBDIR) -lLinkedList -o $(BINDIR)testMain.out

compile:
>$(CC) $(CFLAGS) $(SRCDIR)main.c $(SOURCE) -L$(LIBDIR) -lLinkedList -o $(PROGNAME)
