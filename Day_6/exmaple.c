#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/wait.h>

int main() {
	pid_t process_id;
	int return_val = 1;
	int state;
	
	process_id = fork();
	if(process_id == -1) {
		//When process id is negative there is error with fork();
		printf("Can't fork(), error occured");
		exit(EXIT_FAILURE);
	} else if(process_id== 0) {
		//Child process is created
		
	}
}
