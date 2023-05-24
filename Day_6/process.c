#include<stdio.h>

int main() {
	printf("Hello world1\n");
	printf("PID is %d\n", getpid());
	printf("PID is %d\n", getppid());
	
	int num = fork();
	fork();
	printf("Return from fork is: %d \n", num);
	printf("Hello world2\n");
	printf("PID is %d\n", getpid());
	printf("PID is %d\n", getppid());
	return 0;
}
