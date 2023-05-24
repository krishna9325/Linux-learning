#include<stdio.h>
#include<signal.h>

int a, b;

void add(int sig) {
	printf("Addition is %d \n", a + b);
}

void sub(int sig) {
	printf("Substraction is %d \n", a - b);
}

int main() {
	printf("Enter value for a:  ");
	scanf("%d", &a);
	printf("Enter value for b:  ");
	scanf("%d", &b);
	
	signal(SIGINT, add);
	signal(SIGTSTP, sub); 
	
	while(1);
	//signal(SIGALRM, handle_alarm);
	return 0;
}
