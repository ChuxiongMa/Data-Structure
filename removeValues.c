#include <stdio.h>

#include <malloc.h>

#include <assert.h>



typedef struct node_t {

  int val;

  struct node_t *next;

} node;



/* For all these examples the <var>1 is the input list <var>2 is the 

   output after removing all 2s */

int a1[] = { 2, 2 };

int a2[] = { };



int b1[] = { 3, 2 };

int b2[] = { 3 };



int c1[] = { 2,2,2,2,2,3, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 4, 2,2,2,2,2,2 };

int c2[] = { 3, 4 };



node*  makeList( int * a, int l ) {

  int i = 1;

  node * cur = NULL;

  node * head = NULL;

  if( l == 0 )

    return NULL;

  head = malloc( sizeof( node* ) );

  head->val = a[0];

  cur = head;

  while( i < l ){

    cur->next = malloc( sizeof ( node* ) );

    cur = cur->next;

    cur->val = a[ i ];

    i++;

  }

  cur->next = NULL;

  return head;

}



int verifyList( node* n, int * a, int l ){

  int i = 0;

  while ( i < l && n ) {

    if( n->val != a[ i ] ){

      return 0;

    }

    i++;

    n = n->next;

  }

  return i == l && !n;

}



node* removeMatching1(node* head, int val ) {

//	printf("%d\n", head->val);

	node *temp = head;

	while(temp!=NULL&&temp->val == val){

		//free but head still point to it, val is random var

		head = head->next;

		free(temp);

		temp = head;

		

	}

	//printf("%d\n", head->val);

	node *cur = temp;

	while(temp!=NULL){

		if((temp->val == val)){
			cur->next = temp->next;

			free(temp);

			temp = cur;

			

		}

		cur = temp;

		temp = temp->next;

	        

	}

	//printf("%d\n", head->val);

	//head = head->next;

	return head;



}



void removeMatching(node** head, int val ) {

	node* temp = *head;
	while(temp!=NULL && temp->val == val){
		*head = temp->next;
		free(temp);
		temp = *head;//?
	}
	
	node* pre;
	node* next;
	while(temp!=NULL){
		if(temp->val == val){
			next=temp->next;
			pre->next=next;
			free(temp);
			temp=next;
		}else{
			pre = temp;
			temp=temp->next;}
	}
	
}





void display(node* head){

	node* temp = head;

	while(temp!=NULL){

		printf("%d ", temp->val);

		temp = temp->next;	

	}

	printf("\n");

}



// Runs a test that checks that for a given input/expected array

//   we get the expected arrays when all is said and done

//int check( int* a1, int l1, int*a2, int l2 ) 

void check( int* a1, int l1) {

	node *ll = makeList( a1, l1 );

	display(ll);

	removeMatching(&ll, 2);

	display(ll);

}



int main(){



 check(c1, sizeof(c1)/sizeof(int));



}
