#include <stdio.h>

void push(int stack[], int *top, int maxSize, int element){
	if(*top == maxSize - 1){
		printf("\nStack Overflow!\n");
	}
	else{
		(*top)++;
		stack[*top] = element;
		printf("\n%d pushed to stack\n", element);
	}
}

void pop(int stack[], int *top){
	if(*top == -1){
		printf("\nStack Underflow!\n");
	}
	else{
		printf("\n%d popped from stack\n", stack[*top]);
		(*top)--;
	}
}

void peek(int stack[], int *top){
	if(*top == -1){
		printf("\nStack is empty!\n");
	}
	else{
		printf("Top element: %d\n", stack[*top]);
	}
}

void display(int stack[], int *top){
	if(*top == -1){
		printf("\nStack is empty!\n");
	}
	else{
		printf("\nElements in the stack: \n");
		int i;
		for(i=*top; i>=0; i--){
			printf("%d", stack[i]);
			printf("\n");
		}
		
	}
}

void main(){
	int maxSize = 5, top = -1;
	int choice, stack[maxSize], element;
	
	printf("\nStack Operations:\n \n1. Push \n2. Pop \n3. Peek \n4. Display \n5. Exit\n");
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\nEnter element to push: ");
				scanf("%d", &element);
				push(stack, &top, maxSize, element);
				break;
			case 2:
				pop(stack, &top);
				break;
			case 3:
				peek(stack, &top);
				break;
			case 4:
				display(stack, &top);
				break;
			case 5:
				printf("\nExiting!");
				break;
			default:
				printf("\nInvalid Choice!");
		}
	}while(choice != 5);
}
