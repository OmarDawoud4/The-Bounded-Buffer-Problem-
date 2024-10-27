#include <stdio.h>
#include "shared.h"

extern int count; // Current count of items in the buffer

void display_buffer_status() {
    printf("Current buffer status: %d/%d items\n", count, BUFFER_SIZE);
}
