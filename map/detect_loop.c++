#include <iostream>
#include<set>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 

bool detectLoop(struct Node *h){
	set<Node*> s;
	Node *temp = h;

	while(temp != NULL){
		if(s.count(temp)==1){
			return true;
		}
		s.insert(temp);
		temp=temp->next;
	}
	return false;
}



/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    
    cout<< head<< endl;
    cout<< &head <<endl;
//    cout<< *head<< endl;	
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}
