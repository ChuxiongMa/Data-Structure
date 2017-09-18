#include <stdio.h>
#include <stdlib.h>

typedef struct node{

	int data;
	struct node* next;
} node;

node *create(int data, node* next){
	node * new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL){
		printf("Error creating a new node.\n");
		exit(0);
	}
	new_node->data = data;
	new_node->next = next;

	return new_node;
}

node* addFront(node* head, int data){

	node* new_node = create(data, head);
	head = new_node;
	return head;

}

node* addBack(node* head, int data){

	if(head == NULL){
		return NULL;
	}

	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	node* new_node = create(data, temp->next);
	temp->next = new_node;
	
	return new_node;
}

node* insert_after(int data, node* head, node* pre){

	if(head == NULL || pre == NULL){
		return NULL;
	}
	node* temp = head;
	while(temp != pre){
		temp = temp->next;
	}
        if(temp != NULL){
		node* new_node = create(data, temp->next);
		temp->next = new_node;
		return new_node;
	}else{
		return NULL;
	}
}

void display(node* head){
	node* temp = head;
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->next;
	}

}

node* remove_front(node* head){

	if(head == NULL){
		return NULL;
	}
	
	node* temp = head;
	head = temp->next;
	temp->next = NULL;

	if(temp == head){
		head = NULL;
	}

	free(temp);
	return head;

}

node* reverse(node* head){
	if(head == NULL){
		return NULL;
	}
	node* temp = head;
	node* next = NULL;
	node* pre = NULL;
	while(temp != NULL){
		next = temp->next;
		temp->next=pre;
		pre=temp;
		temp=next;
	}

	return pre;
}


int main(){

	node* head = NULL;
	head = addFront(head, 1);
	head = addFront(head, 2);
	head = addFront(head, 3);
	addBack(head, 4);
	display(head);
	head = reverse(head);
	display(head);

}
