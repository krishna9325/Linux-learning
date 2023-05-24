#include<stdio.h>

void TestFunc();

static void StaticFunc();

void TestFunc() {
	int i = 0;
	printf("In TestFunc()\n");
	
	for(int i=0; i < 100; i++) {
		StaticFunc();
	}
}

static void StaticFunc() {
	int i = 0;
	printf("In StaticFunc()\n");
	
	for(int i=0; i < 10000000; i++);
}

int main() {
	printf("In main\n");
	TestFunc();
	return 0;
}
