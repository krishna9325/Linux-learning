#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *functionC(); 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter =0;

main() {
	int rc1, rc2;
	pthread_t thread1, thread2;
	
	/* create independent threads each of which will execute functionC */
	
	if(rc1 = pthread_create(&thread1, NULL, &functionC, NULL)) {
		printf("Thread creation failed: %d\n", rc1);
	}
	
	if(rc2 = pthread_create(&thread2, NULL, &functionC, NULL)) {
		printf("Thread creation failed: %d\n", rc2);
	}
	
	/*Wait till function are complete before main continues. Unless we wait we run the risk of executing an exit which will terminate the process and all threads before the threads have completed */

}

void *functionC() {
	pthread_mutex_lock(&mutex1);
	counter++;
	printf("Counter value: %d\n", counter);
	pthread_mutex_unlock(&mutex1);
}
