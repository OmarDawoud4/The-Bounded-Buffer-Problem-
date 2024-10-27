#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "shared.h"

extern int buffer[BUFFER_SIZE];
extern int count;
extern int produced_items;

void* consumer(void* arg) {
    while (1) { // Infinite loop
        sleep(2); // Simulate time taken to consume
        sem_wait(&full); // Wait for a full slot
        pthread_mutex_lock(&mutex); // Lock the buffer

        if (count > 0) {
            // Remove an item from the buffer
            int item = buffer[count - 1]; // Stack behavior
            count--;
            printf("Consumed: %d\n", item);
        }

        display_buffer_status(); // Updated function call

        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&empty); // Signal that there is an empty slot
    }
    return NULL; // End the thread
}
