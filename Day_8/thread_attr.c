#include<stdio.h>
#include<pthread.h>

void *thread_function(void *arg) {

	int i;
	for(i =0; i< 10; i++) {
		printf("Thread %d: %d \n", (int)arg, i);
		sleep(1);
	}
	return NULL;
}

int main() {
	pthread_t thread1, thread2;
	pthread_attr_t tattr;
	
	//initialize the thread attribute
	pthread_attr_init(&tattr);
	
	//set the stack size of the thread
	pthread_attr_setstacksize(&tattr, 1024*1024);
	
	//create 2 threads
	pthread_create(&thread1, &tattr, thread_function, (void*)1);
	pthread_create(&thread2, &tattr, thread_function, (void*)2);
	
	//wait for the threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	return 0;

}
