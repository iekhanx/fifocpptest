#
#   21/03/2014 @ik
#
CC = g++
CFLAGS = -Wall -g
PREFIX = /home/iekhanx/bin
TARGET = classes_2

all: $(TARGET).cpp $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm -rf $(TARGET).o
	rm -rf $(TARGET)

install:
	cp -v $(TARGET) $(PREFIX)
   
