#ifndef SHARED_H
#define SHARED_H

#include <semaphore.h>
#include <pthread.h>

#define BUFFER_SIZE 5 
#define ITEM_COUNT 20 

extern sem_t empty; 
extern sem_t full;  
extern pthread_mutex_t mutex; 

void* producer(void* arg); 
void* consumer(void* arg); 
void display_buffer_status(); 

#endif 
