#using gcc compiler
CC = gcc

#output path and filename
BINARY = ./build/prefix

#sources directory
SRC = source/decode.c source/leitura.c source/tree.c source/main.c 

#includes directory
INCLUDES = ./includes

#libraries and flags
LIBS = -lm
FLAGS = -Wall -g

all: compile run

compile:
	$(CC) $(FLAGS) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)

run:
	$(BINARY)

clean:
	rm *.o