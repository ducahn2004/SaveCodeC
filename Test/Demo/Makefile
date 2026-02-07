CC = gcc
SRCS = $(Wildcard *.c)
TARGET = $(SRCS:.c=)


all: $(TARGET)

%: %.c
	$(CC)  -o $@ $<

clean:
	rm -f $(TARGET)	