#ifndef CHASHMAP_H
#define CHASHMAP_H

typedef struct Node {
    char *key;
    void *value;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node **buckets;
} HashMap;

HashMap* createHashMap(int size);

void put(HashMap *map, int key, void *value);
void *get(HashMap *map, int key);
bool remove(HashMap *map, int key);

#endif