#include <stdlib.h>

#include <assert.h> 

struct node {

	int val;

	struct node* next;

};



struct node* createList(int nodes);

struct node* freeList(struct node* list, int nodes);



struct node* createList(int nodes) {

	int i = 0;

	struct node* list =

		(struct node*) malloc(sizeof(struct node) * nodes);

	assert(list);

	for (i = nodes - 1; i >= 0; --i) {

		list[i].val = (nodes - i) - 1;

		list[i].next = list + (i - 1);

	}

	list[0].next = NULL;

	return &list[nodes - 1];

}



struct node* freeList(struct node* list, int nodes) {

	free(&list[1 - nodes]);

}
