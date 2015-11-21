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
<<<<<<< HEAD
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)
=======
	$(CC) $(FLAGS) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)
>>>>>>> ef117d04a09fc1ed1ce79b6b93cb1e18ccb21347

run:
	$(BINARY)

clean:
	rm *.o