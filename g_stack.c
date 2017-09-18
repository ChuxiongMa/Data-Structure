#include<stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack
{
    // Any data type can be stored in this stack
    void  *data; 
    struct stack *next;
} stack;

void push(stack** head, void *data, size_t ele_size){
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->data=malloc(ele_size);

	//Allocate memory for it
	int i;
   	for (i=0; i<ele_size; i++){
       		 *(char*)(temp->data + i) = *(char *)(data + i);}

	temp->next = *head;
	*head = temp;

}

void* pop(stack** head, void* element){

	stack* temp = *head;
	element = temp->data;
	*head = temp->next;
	free(temp);
	return element;

}

int empty(stack* head){
	return head == NULL ? 1 : 0;
}

void printList(struct stack *stack, void (*fptr)(void *))
{
    printf("Stack: ");
    while (stack != NULL)
    {
        (*fptr)(stack->data);
        stack = stack->next;
    }
	printf("\n\n");
}
 

void printInt(void *n)
{
   
   printf("%d ", *(int *)n);
}

void printChar(void *n)
{
   
   printf("%c ", *(char *)n);
}
 

int main(){

	printf("Int stack: \n");
	stack* int_stack = NULL;
	int a[5]={1,2,3,4,5};
	for(int i = 0; i<5; i++){
		push(&int_stack, &a[i], sizeof(int));
		printList(int_stack, printInt);
	}

	void* int_element;
	printf("\nNow pop elements from stack\n");
	
	int_element = pop(&int_stack, int_element);
	printf("element popped: %d\n",  *(int*)int_element);
	printList(int_stack, printInt);
	
	int b = 100;
	int_element = pop(&int_stack, int_element);
	push(&int_stack, &b, sizeof(int));
	printf("element popped: %d\n",  *(int*)int_element);
	printList(int_stack, printInt);
	//while(!empty(int_stack)){ 
	//	int_element = pop(&int_stack, int_element);
	//	printf("element popped: %d\n",  *(int*)int_element);
	//	printList(int_stack, printInt);
        //}
     
	printf("Memory Freed\n");

	printf("\n\nString stack: \n");
	stack* char_stack = NULL;
	char* string_array="abcde";
        
	
	for(int j=0; j<strlen(string_array); j++){
		push(&char_stack, &string_array[j], sizeof(char));
		printList(char_stack, printChar);
	}

	void* char_element = malloc(sizeof(char));
	printf("\nNow pop elements from stack\n");
	
	//char ele = 'c';
	while(!empty(char_stack)){
		printf("element popped: %c\n", *(char*)pop(&char_stack, char_element));
		//pop(&char_stack, &ele);
		//printf("element popped: %c\n", char_element);
		printList(char_stack, printChar);
	}
	free(char_element);
	printf("Memory Freed\n");

	return 0;
}

