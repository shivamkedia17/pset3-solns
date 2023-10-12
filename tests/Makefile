CC = gcc
CFLAGS = -Wall -g
EXEC_FILE = test1

$(EXEC_FILE): main.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
	$(CC) $(CFLAGS) $^ -o $@ 
	# rm -f $^

clean:
	rm -f *.o ../hashing/hashing.o ../hashing/hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o $(EXEC_FILE)