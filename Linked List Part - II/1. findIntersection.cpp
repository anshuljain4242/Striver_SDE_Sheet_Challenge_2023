#include<iostream>
#include<unordered_map>
using namespace std;

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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    // Optimal : TC -> O(2m), m is the length of the shorter list, SC -> O(1)
    
    if(!firstHead || !secondHead)   return NULL;

    Node* first = firstHead;
    Node* second = secondHead;

    while(first != second)
    {
        first = first == NULL ? secondHead : first -> next;
        second = second == NULL ? firstHead : second -> next;
    }
    
    return first;  

    // Better : Storing addresses in the hash map
    // TC -> O(n+m), SC -> O(n)
    /*
    unordered_map<Node*, int> m;

    Node* first = firstHead;
    Node* second = secondHead;

    while(first != NULL)
    {
        m[first]++;
        if(m[first] > 1)
            return first;
        first = first -> next;    
    }  
    while(second != NULL)
    {
        m[second]++;
        if(m[second] > 1)
            return second;
        second = second -> next;    
    } 
    return NULL;
    */
    
}