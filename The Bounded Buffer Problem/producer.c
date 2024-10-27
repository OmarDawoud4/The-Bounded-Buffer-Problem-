#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "shared.h"

extern int buffer[BUFFER_SIZE];
extern int count;
extern int produced_items;

void* producer(void* arg) {
    while (1) { // Infinite loop
        int item = rand() % 100; // Produce a random item
        sleep(1); // Simulate time taken to produce

        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Lock the buffer

        // Add the item to the buffer
        buffer[count] = item;
        count++;
        produced_items++;
        printf("Produced: %d\n", item);

        display_buffer_status(); // Updated function call

        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&full); // Signal that there is a new item
    }
    return NULL; // End the thread
}
