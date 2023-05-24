#include<stdio.h>
#define err_sys printf
int main() {
	int n;
	int fd[2];
	int pid;
	char line[20];
	
	if(pipe(fd) < 0) {
		printf("Pipe error");
	}
	
	if((pid = fork()) < 0) { 
		printf("Fork error");
	} else if(pid > 0) /*parent*/ {	close(fd[0]);
		write(fd[1], "Hello world\n", 12);
	} else { 
		close(fd[1]);
		n = read(fd[0], line, 20);
		write(1, line, n);
	}
	exit(0);
}
