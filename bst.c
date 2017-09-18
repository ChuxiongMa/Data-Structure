

#include <stdlib.h> 
#include<stdio.h>


/* Example BST:

*

* 8

* / \

* 4 12

* / \ / \

* 1 7 11 20

*/





typedef struct node {

	int value;

	struct node *left, *right, *parent;

} node_t;



struct node * findMin(struct node *n) {
	while(n->left!=NULL){
		n=n->left;
	}
	return n;
}
struct node * findMax(struct node *n) {
        while(n->right!=NULL){
                n=n->right;
        }
        return n;
}
struct node * findSuccessor(struct node *n) {
	if(n->right != NULL){return findMin(n->right);}
	else{
		while(n->parent!=NULL && n != n->parent->left){
			n=n->parent;		}

		return n->parent;
	}

}
struct node * findProceduer(struct node *n) {

	if(n->left != NULL){return findMax(n->left);}
	else{
		while(n->parent != NULL && n != n->parent->right){
			n=n->parent;
		}
		return n->parent;
	}
}

void printBst(struct node *n) {

	if(n->left!=NULL){printBst(n->left);}
	printf("%d ", n->value);
	if(n->right!=NULL){printBst(n->right);}

}
void printBstNR(struct node *root) {

		node_t* n;

		for (n = findMin(root); ; n = findSuccessor(n)) {

			printf("%d ", n->value);

		}

	}



node_t* insertNode(node_t** root, int newval)

	{

		node_t *n;

		if (!(*root)) {

			n = (node_t*)calloc(1, sizeof(node_t));

			n->value = newval;

			*root = n;

		}

		else if (newval < (*root)->value) {

			n = insertNode(&((*root)->left), newval);

			if ((*root)->left == n) n->parent = *root;

		}

		else {

			n = insertNode(&((*root)->right), newval);

			if ((*root)->right == n) n->parent = *root;

		}

		return n;

}

int main()

{

		node_t* root = NULL;

		int data[] = { 8, 4, 12, 1, 7, 11, 20 };

		int i, len = sizeof(data) / sizeof(int);



		for (i = 0; i < len; i++) insertNode(&root, data[i]);



		printf("\ntraversal w/o recursion: ");

		printBstNR(root);

		printf("\ninorder: ");

		printBst(root);



		printf("\nget min: %d", findMin(root)->value);

		printf("\nget successor: %d", findSuccessor(root->right->left)->value);
		printf("\nget proceduer: %d", findProceduer(root->right->left)->value);

		//printBst(root);

		printf("\n");

		return 0;

}


