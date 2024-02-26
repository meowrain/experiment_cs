# Project: Project1
# Makefile created by Red Panda C++ 2.25

CPP      = g++
CC       = gcc
OBJ      = student.o utils.o main.o file.o
LINKOBJ  = student.o utils.o main.o file.o
CLEANOBJ  =  student.o utils.o main.o file.o Project1
LIBS     = 
INCS     =  
CXXINCS  =  
BIN      = Project1
CXXFLAGS = $(CXXINCS)  -g3 -pipe -Wall -D__DEBUG__
CFLAGS   = $(INCS)  -g3 -pipe -Wall -D__DEBUG__
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	-$(RM) $(CLEANOBJ) > /dev/null 2>&1

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

student.o: student.c student.h all.h utils.h
	$(CC) -c student.c -o student.o $(CFLAGS) 

utils.o: utils.c all.h utils.h
	$(CC) -c utils.c -o utils.o $(CFLAGS) 

main.o: main.c student.h all.h file.h
	$(CC) -c main.c -o main.o $(CFLAGS) 

file.o: file.c all.h file.h
	$(CC) -c file.c -o file.o $(CFLAGS) 
