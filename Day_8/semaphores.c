#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

unsigned int cnt = 0; /* shared */
#define NITERS 10000000
sem_t sem; /* semaphore */


void Sem_init(sem_t *sem, int pshared, unsigned int value) {
	if(sem_init(sem, pshared, value) == -1) {
		//perror("sem init");
	}
}


/* p operation on semaphore sem */
void P(sem_t *sem) {
	if(sem_wait(sem) == -1) {
		//unix_error("P");
	}
}


/* V operation on semaphore sem */
void V(sem_t *sem) {
	if(sem_post(sem) == -1) {
		//unix_error("V");
	}
}


void *count(void *arg) {
	int i;
	for(i=0; i<NITERS; i++) {
		P(&sem);
		cnt++;
		V(&sem);
	}
	return NULL;
}


int main() {
	pthread_t tid1, tid2;
	
	Sem_init(&sem, 0, 1); /* sem = 1 */
	
	pthread_create(&tid1, NULL, count, NULL);
	pthread_create(&tid2, NULL, count, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	if(cnt != (unsigned) NITERS*2)
		printf("BOOM! cnt= %d\n", cnt);
	else 
		printf("OK cnt= %d\n", cnt);
	return 0;
}
