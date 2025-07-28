#include "hashmap_c.h"
#include <stdlib.h>
#include <string.h>

HashMap *createHashMap(size_t capacity) {
  HashMap *map = malloc(sizeof(HashMap));
  map->capacity = capacity;
  map->size = 0;
  map->buckets = calloc(capacity, sizeof(Entry *));

  return map;
}

unsigned long hash(const char *str) {
  unsigned long hash = 6969;
  int c;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}

void put_entry(HashMap *map, const char *key, void *value) {
  unsigned long index = hash(key) % map->capacity;
  Entry *entry = map->buckets[index];

  while (entry) {
    if (strcmp(entry->key, key)) {
      entry->value = value;
      return;
    }
    entry = entry->next;
  }

  entry = malloc(sizeof(Entry));
  entry->key = strdup(key);
  entry->value = value;
  entry->next = map->buckets[index];
  map->buckets[index] = entry;
  map->size++;
}

void *get_entry(HashMap *map, const char *key) {
  unsigned long index = hash(key) % map->capacity;
  Entry *entry = map->buckets[index];

  while (entry) {
    if (strcmp(entry->key, key)) {
      return entry->value;
    }
    entry = entry->next;
  }
  return NULL;
}