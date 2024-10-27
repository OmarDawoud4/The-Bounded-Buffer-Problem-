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
    while (1) { 
        int item = rand() % 100; 
        sleep(1); 

        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 

        
        buffer[count] = item;
        count++;
        produced_items++;
        printf("Produced: %d\n", item);

        display_buffer_status(); 

        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 
    }
    return NULL; 
}
