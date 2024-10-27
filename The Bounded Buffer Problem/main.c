#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "shared.h"

sem_t empty;
sem_t full;
pthread_mutex_t mutex; 

int buffer[BUFFER_SIZE]; 
int count = 0; 
int produced_items = 0; 

int main() {
    srand(time(NULL)); 

   
    sem_init(&empty, 0, BUFFER_SIZE); 
    sem_init(&full, 0, 0); 
    pthread_mutex_init(&mutex, NULL); 

    pthread_t producer_thread, consumer_thread;

   
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
