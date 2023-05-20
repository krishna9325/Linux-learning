#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node* next;
};

struct node* last = NULL;

void insertAtFront(int data) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node)); 
	
	if(last == NULL) {
		temp->info = data;
		temp->next = temp;
		last = temp;
	}
	else {
		temp->info = data;
		temp->next = last->next;
		last->next = temp;
	}
}

void viewlist() {
	if(last == NULL) {
		printf("List is empty");
	} else {
		struct node* temp;
		temp = last->next;
		printf("Circular list data is: \n");
		do {
			printf("%d ", temp->info);
			temp = temp->next; 
		} while(temp != last->next);
		printf("\n");
	}
}

int main() {
	insertAtFront(10);
	insertAtFront(20);
	insertAtFront(30);
	insertAtFront(40);
	insertAtFront(50);
	
	viewlist();
	return 0;
	
}
