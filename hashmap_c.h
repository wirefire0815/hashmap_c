#ifndef CHASHMAP_H
#define CHASHMAP_H
#include <stdbool.h>
#include <stddef.h>

typedef struct Entry {
    char *key;
    void *value;
    struct Entry* next;
} Entry;

typedef struct {
    Entry **buckets;
    size_t capacity;
    size_t size;
} HashMap;

HashMap* createHashMap(size_t capacity);

unsigned long hash(const char *str);
void put_entry(HashMap *map, const char *key, void *value);
void *get_entry(HashMap *map, const char *key);
bool remove_entry(HashMap *map, const char *key);

#endif