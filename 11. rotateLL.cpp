#include<iostream>
using namespace std;

class Node {
public:
     int data;
     Node *next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k) 
{
     if(head == NULL || head -> next == NULL || k==0)
          return head;

     int len = 1;
     Node* temp = head;
     while(temp -> next != NULL) 
     {
          temp = temp -> next;
          len++;
     }     

     temp -> next = head;
     k = k%len;
     k = len-k;

     while(k--)
     {
          temp = temp -> next;
     }
     head = temp -> next;
     temp -> next = NULL;

     return head;
}