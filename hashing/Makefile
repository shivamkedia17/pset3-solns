CC = clang
CFLAGS = -Wall -g
EXEC_FILE = testhash

$(EXEC_FILE): main.o hashing.o hashmap.o ../helpers/helpers.o ../prng/mt19937-64.o
	$(CC) $^ -o $@ $(CFLAGS)
	rm -f *.o ../helpers/*.o ../prng/*.o

clean:
	rm -f *.o ../helpers/*.o ../prng/*.o $(EXEC_FILE)