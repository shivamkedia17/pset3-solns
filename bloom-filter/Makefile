CC = gcc
CFLAGS = -Wall -g
EXEC_FILE = bloomfilter

$(EXEC_FILE): main.o bloomfilter.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
	$(CC) $^ -o $@ $(CFLAGS)
	rm -f $^

clean:
	rm -f *.o bloomfilter.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o $(EXEC_FILE)