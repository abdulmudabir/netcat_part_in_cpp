
# Makefile for netcat_part

cc = g++

CFLAGS = -Wall -Wextra -g

all: netcat

netcat: netcat.o client.o server.o
	$(CC) -lssl netcat.o client.o server.o -o netcat_part

clean:
	rm -vf *.o *~ netcat_part

superclean:
	rm -vf *.o *~ netcat_part results.txt
