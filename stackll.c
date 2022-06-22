#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *top = NULL;

void push(int x) {
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = x;
	if (top == NULL) {
		newnode->next = NULL;
	}
	else {
		newnode->next = top;		
	}
	top = newnode; 				
	printf("Value Inserted\n");
}

int pop() {
	
		struct node *del = top;
		int del_data = top->data;
		top = top->next;
		free(del);
		return del_data;
}

void display() {
	if (top == NULL) {
		printf("\nEmpty Stack\n");
	} else {
		printf("The stack is \n");
		struct node *pos= top;
		printf("%d\n", pos->data);
		pos= pos->next;
		while (pos->next != NULL) {
			printf("%d\n", pos->data);
			pos= pos->next;
		}
		printf("%d\n\n", pos->data);
	}
}

int main() {
	int choice, x;
	printf("\nIMPLEMENTATION OF STACK USIN LINKED LIST\n");
	while (1) {
		printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nYour choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter the value to push: ");
			scanf("%d", &x);
			push(x);
			break;
		case 2:
			if (top == NULL) {
				printf("\nStack is underflow\n");
			} 
			else {
				printf("\nPopped element is :%d\n", pop());
			}
			break;
		case 3:
			display();
			break;
		case 4:
			printf("Thankyou\n");
			exit(0);
			break;
		default:
			printf("\nWrong Choice\n");
		}
	}
}

