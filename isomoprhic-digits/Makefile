CC = gcc
CFLAGS = -Wall -g
EXEC_FILE = isomorphic

$(EXEC_FILE): main.o isomorphic.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
	$(CC) $(CFLAGS) $^ -o $@ 
	# rm -f $^

clean:
	rm -f *.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o $(EXEC_FILE)