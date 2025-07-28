#include "hashmap_c.h"
#include <stdio.h>

int main() {
  HashMap *map = createHashMap(10);
  put_entry(map, "Vogel", "pssss");
  void *v = get_entry(map, "Vogel");

  printf("Hello, World!");
}