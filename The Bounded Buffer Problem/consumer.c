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
    while (1) { 
        sleep(2); 
        sem_wait(&full); 
        pthread_mutex_lock(&mutex); 

        if (count > 0) {
           
            int item = buffer[count - 1]; 
            count--;
            printf("Consumed: %d\n", item);
        }

        display_buffer_status(); 

        pthread_mutex_unlock(&mutex); 
        sem_post(&empty); 
    }
    return NULL; 
}
