#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h> 
#include <unistd.h>  

//globals
int threadID = 0; 
int counter = 0;
//mutex
pthread_mutex_t lock;

void *loops(void *arg){ 
  int i = 0;  
  threadID++;

  pthread_mutex_lock(&lock);
  printf("Thread: %d started! \n", threadID);

  for(i=0; i<5000; i++){
    counter++;
    printf("Thread running: %d \n", counter);
  }

  printf("Thread: %d finished... \n", threadID);
  pthread_mutex_unlock(&lock);
}

int main(){ 
  int i = 0;
  pthread_t threads; 

  for(i=0; i<2; i++){ //loop to create i threads.
    pthread_create(&threads, NULL, loops, NULL);

    pthread_join(threads, NULL); 
  }

  exit(0); 
}