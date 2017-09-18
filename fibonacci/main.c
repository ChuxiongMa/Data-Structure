#include <stdio.h> 

#include <stdlib.h> 

#include "list.h" 

/**

* Given a linked list of the structure:

struct node {

int val;

struct node* next;

};

print out the fibonacci nodes e.g. the 1st, 2nd, 3rd, 5th, 8th... nodes

up until the list ends.

*/



int main(int argc, char** argv) {

	if (argc != 2) {

		printf("usage fib num --you gave %d args\n", argc - 1);

		exit(0);

	}

	int nodes = atoi(argv[1]);



	if (nodes < 1) {

		printf("num must be a positive number --you gave %d\n", nodes);

	}



	struct node* list = createList(nodes);

	// ... 
       
	struct node* cur = list;
	if(nodes == 1){
		printf("%d ", cur->val);
	}else{

		int first=1;
		int sec=1;
		int fib = 1;
		int count=1;
		while(fib<=nodes){
			if(count==fib){
				printf("%d ", cur->val);
				first=sec;
				sec=fib;
				fib=first+sec;}
			cur=cur->next;
			count++;
	}
	}

	printf("\n");
	struct node* temp = list;
	while(temp != NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}
  	printf("\n");

	freeList(list, nodes);

}
