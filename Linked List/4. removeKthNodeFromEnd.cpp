#include<iostream>

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
// Better : counting the number of nodes(n), reaching the node to be deleted by n-k+1. TC -> O(2n)
// Optimal : TC -> O(n), SC -> O(1)

Node* removeKthNode(Node* head, int K)
{
    Node* dumy = new Node();
    dumy -> next = head;

    Node* fast = dumy;
    Node* slow = dumy;

    for(int i=1; i<=K; i++)
    {
        fast = fast -> next;
    }

    while(fast -> next != NULL)
    {
        fast = fast -> next;
        slow = slow -> next;
    }

    slow -> next = slow -> next -> next;

    return dumy -> next;

}