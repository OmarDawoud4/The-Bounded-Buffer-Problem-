#ifndef SHARED_H
#define SHARED_H

#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5 // Fixed buffer size
#define ITEM_COUNT 20 // Total items to produce

extern sem_t empty; // Semaphore for empty slots
extern sem_t full;  // Semaphore for full slots
extern pthread_mutex_t mutex; // Mutex for buffer access

void* producer(void* arg); // Declare producer function
void* consumer(void* arg); // Declare consumer function
void display_buffer_status(); // Updated function prototype

#endif // SHARED_H
