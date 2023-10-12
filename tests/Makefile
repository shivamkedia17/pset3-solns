CC = gcc
DEBUG_FILE = test1-debug
EXEC_FILE = test1
INCLUDES = ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
CURRENT = test1.o

debug: CFLAGS = -Wall -g

debug: main.o $(CURRENT) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $(DEBUG_FILE)

$(EXEC_FILE): CFLAGS = -Wall

$(EXEC_FILE): main.o $(CURRENT) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $^

clean:
	rm -f *.o $(INCLUDES) $(EXEC_FILE) $(DEBUG_FILE)