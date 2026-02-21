TARGET = steamer

SRCS = steamer.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -g -lncurses -O2

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
