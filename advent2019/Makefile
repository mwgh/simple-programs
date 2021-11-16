CC = g++
CFLAGS = -g -Wall -Wextra
SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

all: $(PROGS)

%: %.cpp
	$(CC) $(CFLAGS)  -o $@ $<

clean:
	rm -f $(PROGS)
