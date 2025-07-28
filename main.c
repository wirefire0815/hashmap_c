#include "hashmap_c.h"
#include <stdio.h>

int main() {
  HashMap *map = createHashMap(10);

  put_entry(map, "Vogel", "pssss");

  remove_entry(map, "Vogel");
  void *v = get_entry(map, "Vogel");

  printf("%s\n", (char *)v);
  printf("Hello, World!");
}