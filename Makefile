
# Makefile for netcat_part

CC = g++

CFLAGS = -c -Wall -Wextra -g
# LDFLAGS = -lssl

SOURCES = netcat_part.cxx
OBJECTS = $(SOURCES:.cxx=.o)
EXECUTABLE = netcat_part

all: netcat

netcat: $(OBJECTS)
	$(CC) $^ -o $(EXECUTABLE)  # $^ => all dependencies.

%.o: %.cxx
	$(CC) $(CFLAGS) $< -o $@   # $< => each dependency; $@ => each target.

clean:
	rm -vf *.o *~ netcat_part

superclean:
	rm -vf *.o *~ netcat_part results.txt
