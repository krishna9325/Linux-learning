#include<stdio.h>

int main() {
	int num1=0, num2=0;
	printf("Enter the num1 \n");
	scanf("%d", &num1);
	
	printf("Enter the num2 \n");
	scanf("%d", &num2);
	
	int sum = num1 + num2;
	
	printf("Add is %d \n", sum);
	return 0;
}
