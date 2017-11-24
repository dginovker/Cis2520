.RECIPEPREFIX = >
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

INCLUDES = -linclude

BINDIR = bin/
SRCDIR = src/
OBJDIR = obj/
LIBDIR = lib/

SOURCE = $(SRCDIR)intListTest.c $(SRCDIR)LinkedListAPI.c $(SRCDIR)Test.c $(SRCDIR)HashTableAPI.c $(SRCDIR)HashTableTest.c $(SRCDIR)userHashFunctions.c $(SRCDIR)displayDictionary.c $(SRCDIR)modifyDictionary.c $(SRCDIR)spellCheck.c
PROGNAME = $(BINDIR)main.out

default: compile

ranlib:
>ranlib $(LIBDIR)*

test:
>$(CC) $(CFLAGS) $(SRCDIR)testMain.c $(SOURCE) -o $(BINDIR)testMain.out

compile:
>$(CC) $(CFLAGS) $(SRCDIR)main.c $(SOURCE) -o $(PROGNAME)
