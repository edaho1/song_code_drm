#include <stdio.h>
#include <inttypes.h>
#include "map.h"

int main()
{
    map_str_t m;
    map_init(&m);

    map_set(&m, "testkey", "hello");

    char **val = map_get(&m, "testkey");
    for (int i = 0; i < 4; i++){
        if (val) {
            printf("value: %s\n", (val[i]));
            } else {
            printf("value not found\n");
        }
    }

}