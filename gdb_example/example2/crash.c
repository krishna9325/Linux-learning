#include<stdio.h>
int div(int, int);

int main() {
	int x=5;
	int y=2;
	printf("Div is %d \n", div(x,y));
	printf("Div is %d \n", div(x,0));
	return 0;
	
}

int div(int a, int b) {
	return a / b;
}
