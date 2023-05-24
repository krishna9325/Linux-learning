#include<stdio.h>

using namespace std;

void setint(int*, int);

int main() {
	int a;
	setint(&a, 10);
	printf("%d\n", a);
	
	int b;
	setint(&b, 100);
	
	printf("%d\n", a);
	
	return 0;
}

void setint(int* ip, int i) {
	*ip=i;
}
