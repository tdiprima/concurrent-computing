CC=gcc
CXX=g++
CFLAGS=-fopenmp -Wall -O2
SOURCES=$(wildcard *.c *.cpp)
TARGETS=$(SOURCES:.c=.out)
TARGETS+=$(SOURCES:.cpp=.out)

all: $(TARGETS)

%.out: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.out: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
