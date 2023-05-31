#include<stdio.h>
#include<pthread.h>

int a = 10;
int b = 20;

void *add() {

	printf("Add is: %d\n", a + b); 
	return NULL;
}


void *sub() {
	printf("Sub is: %d\n", a - b); 
	return NULL;
}


void *mul() {

	printf("Mul is: %d\n", a * b); 
	return NULL;
}


void *div() {
	printf("Div is: %d\n", a / b); 
	return NULL;
}



int main() {
	pthread_t thread1, thread2, thread3, thread4;
	
	//create threads
	pthread_create(&thread1, NULL, add, NULL);
	pthread_create(&thread2, NULL, sub, NULL);
	pthread_create(&thread3, NULL, mul, NULL);
	pthread_create(&thread4, NULL, div, NULL);
	
	//wait for the threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	return 0;

}
