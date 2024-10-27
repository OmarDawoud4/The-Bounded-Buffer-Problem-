#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "shared.h"

sem_t empty; // Semaphore for empty slots
sem_t full;  // Semaphore for full slots
pthread_mutex_t mutex; // Mutex for buffer access

int buffer[BUFFER_SIZE]; // Shared buffer
int count = 0; // Current count of items in the buffer
int produced_items = 0; // Count of produced items

int main() {
    srand(time(NULL)); // Seed random number generator

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE); // Start with all slots empty
    sem_init(&full, 0, 0); // Start with no full slots
    pthread_mutex_init(&mutex, NULL); // Initialize mutex

    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
