CC = gcc
DEBUG_FILE = isomorphic-debug
EXEC_FILE = isomorphic
INCLUDES = ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
CURRENT = isomorphic.o

debug: CFLAGS = -Wall -g

debug: main.o $(CURRENT) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $(DEBUG_FILE)

$(EXEC_FILE): CFLAGS = -Wall

$(EXEC_FILE): main.o $(CURRENT) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $@
	rm -f $^

clean:
	rm -f *.o $(INCLUDES) $(EXEC_FILE) $(DEBUG_FILE)