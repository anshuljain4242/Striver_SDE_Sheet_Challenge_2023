#include<iostream>

class Node {
  public:
      int data;
      Node *next;
      Node() {
          this->data = 0;
          this->next = NULL;
      }
      Node(int data) {
          this->data = data;
          this->next = NULL;
      }
      Node (int data, Node *next) {
          this->data = data;
          this->next = next;
       }
 };

void insertAtEnd(Node* &head, int item)
{
    Node *node = new Node(item);
    if (head == NULL)
    {
        head = node;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
Node* add(Node* &num1, Node* &num2){

    Node* head = NULL;
    int dig = 0;
    int carry = 0;
    int sum = 0;
    while(num1 != NULL || num2 != NULL || carry != 0){

        int val1 = 0;
        if(num1 != NULL)
            val1 = num1 -> data;

        int val2 = 0;
        if(num2 != NULL)
            val2 = num2 -> data;    


        sum = carry + val1 + val2;

        dig = sum % 10;

        insertAtEnd(head,dig);  
        carry = sum/10;
  
        if(num1 != NULL)
            num1 = num1 -> next;

        if(num2 != NULL)    
            num2 = num2 -> next;
    }

    return head;
}
Node *addTwoNumbers(Node *num1, Node *num2)
{
    
    //step1 : traverse both the list and add the corresponding elements
    Node* ans = add(num1,num2);

    return ans;
}