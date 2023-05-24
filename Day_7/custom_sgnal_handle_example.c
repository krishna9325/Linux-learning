#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void error(int sig) {
	printf("Ohh! its floating point error...\n");
	(void) signal(SIGFPE, SIG_DFL);
}

int main() {
	(void) signal(SIGFPE, error);
	int a = 12, b = 0, result;
	result = a / b;
	printf("Result is: %d\n", result);
	return 0;
}
