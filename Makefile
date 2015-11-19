#using gcc compiler
CC = gcc

#output path and filename
BINARY = ./build/prefix

#debug output path and filename
DEBUG = ./debug/prefix

#sources
SRC = source/tree.c source/decode.c source/main.c 

#includes directory
INCLUDES = ./includes

#libraries and flags
LIBS = -lm
FLAGS = -Wall -g -Wextra

all: 
	compile run

compile:
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)

run:
	$(BINARY)

clean:
	rm *.o

debug:
	$(CC) -o $(DEBUG) -I$(INCLUDES) $(SRC) $(FLAGS) $(LIBS)