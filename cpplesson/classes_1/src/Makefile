#
#
# 20/03/2014    @IK
#
CC = g++
CFLAGS = -Wall -g
LDFLAGS = -g
PREFIX = /home/iekhanx/bin
TARGET = classes_1


all: $(TARGET).cpp $(TARGET).o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
	rm -rf $(TARGET).o
	rm -rf $(TARGET)

install:
	cp -v $(TARGET) $(PREFIX)
