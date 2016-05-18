#
# 20/03/2014  @ ik
#
#
CC=g++
CFLAGS = -c -Wall
PREFIX = /home/iekhanx/bin

all: pbasecls

pbasecls: pbasecls.o
	$(CC) -o pbasecls  pbasecls.cpp

clean:
	rm -f pbasecls.o
	rm -f pbasecls

install: pbasecls
	cp ./pbasecls  $(PREFIX)


