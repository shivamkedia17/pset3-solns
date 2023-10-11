#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} Entry;

void initializeTable(Entry table[], bool visited[], int size) {
    for (int i = 0; i < size; i++) {
        table[i].key = -1;
        table[i].value = -1;
        visited[i] = false;
    }
}

void insert(Entry table[], bool visited[], int key, int value) {
    int hash = key % TABLE_SIZE;
    int i = 1;

    while (visited[hash] || table[hash].key != -1) {
        hash = (hash + i * i) % TABLE_SIZE;
        i++;
    }

    table[hash].key = key;
    table[hash].value = value;
    visited[hash] = true;
}

int main() {
    Entry table[TABLE_SIZE];
    bool visited[TABLE_SIZE];

    // Initialize the table and visited flags
    initializeTable(table, visited, TABLE_SIZE);

    // Insert elements using quadratic probing
    insert(table, visited, 5, 42);
    insert(table, visited, 15, 100);
    insert(table, visited, 25, 18);

    // Print the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: Key = %d, Value = %d\n", i, table[i].key, table[i].value);
    }

    return 0;
}
