#include <stdio.h> 
#include <pthread.h>
#include <stdlib.h> 
#include <unistd.h>  

int array1[10], array2[10];

//Only for array 1.
void *loop1(void *Arr){  
  int randNum = 0;
  int i = 0; 

  for(i=0; i<10; i++){
    randNum = rand()%256; //Random number between 0 n 255.
    array1[i] = randNum;
    sleep(0.01); //milliseconds.
  }
  return NULL; 
} 
//Only for array 2.
void *loop2(void *Arr){ 
  int randNum = 0;  
  int i = 0; 
  
  for(i=0; i<10; i++){
    randNum = rand()%256;
    array2[i] = randNum;
    sleep(0.005); //milliseconds.
  }
  return NULL; 
}
//Thread result: AND operation between array1 n array2. 
void *threadResult(void *Arr){ 
  int i = 0; 

  for(i=0; i<10; i++){
    int result = array1[i] & array2[i]; //AND operation.
    printf("Result ASCII of %d is: %c \n", result, result);
    sleep(0.01); //milliseconds.
  }
  return NULL; 
}

int main(){ 
  pthread_t thread1, thread2, thread3; 

  pthread_create(&thread1, NULL, loop1, NULL); 
  pthread_create(&thread2, NULL, loop2, NULL);
  pthread_create(&thread3, NULL, threadResult, NULL); 

  pthread_join(thread1, NULL); 
  pthread_join(thread2, NULL); 
  pthread_join(thread3, NULL); 

  exit(0); 
}
