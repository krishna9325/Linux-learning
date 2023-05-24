#include<stdio.h>
#include<signal.h>

void handle_sigint(int sig) {
	printf("Caught signal %d \n", sig);
}

void handle_alarm(int sig) {
	printf("Alarm called %d \n", sig);
}

int main() {
	signal(SIGINT, handle_sigint); //ctrl +c
	signal(SIGTSTP, handle_sigint); //ctrl + z
	
	signal(SIGALRM, handle_alarm);
	
	//Raising the signal 2 continuously
	while(1) {
		int rc = raise(SIGINT);
		if(rc < 0) {
			perror("raise");
		}
		sleep(1);
		alarm(2);
	}
	
	//{
	//	printf("Hello world\n");
	//	sleep(1);
	//}
	
	
	// signal(SIGTSTP, handle_sigint);
	//Above statement kill the process, when we call it at this stage when we click ctrl + z
	
	return 0;
}
