TARGET = steamer

SRCS = steamer.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -g -lncurses

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
