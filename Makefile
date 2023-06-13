CC := gcc
#CFLAGS := 
DEST := ./build/

all: plurality.c
	mkdir -p build
	$(CC) plurality.c -lcs50 -o $(DEST)/plurality 