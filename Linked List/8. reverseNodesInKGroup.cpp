#include<iostream>
#include<vector>
using namespace std;


class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

Node* reverse(int i, Node* head, int n, int b[])
{
	while(b[i] == 0 && i<n) i++;

	if(head == NULL ||head -> next == NULL || i==n)
		return head;

	Node* prev = NULL, *curr = head, *forw; 
	int k = b[i];
	while(curr != NULL && k--)
	{
		forw = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forw;
	}
	head -> next = reverse(i+1, curr, n, b);

	return prev;	
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	if(head == NULL)
		return NULL;
	return reverse(0,head,n,b);	
}