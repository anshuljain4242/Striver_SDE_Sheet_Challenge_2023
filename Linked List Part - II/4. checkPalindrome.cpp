#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Optimal : TC -> O(n/2) + O(n/2) + O(n/2) + O(n/2) + O(n/2)
// to find middle + to reverse the 2nd half + to compare first and second half +
// (optional) to again find middle + to again reverse the second half into original list
// SC -> O(1)
LinkedListNode<int> *getMiddle(LinkedListNode<int> *&head)
{
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

LinkedListNode<int> *reverseLL(LinkedListNode<int> *&head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head)
{

    if (head == NULL || head->next == NULL)
        return true;
    // step 1: get middle node
    LinkedListNode<int> *mid = getMiddle(head);

    // step2 : reverse the list after the middle node
    LinkedListNode<int> *temp2 = mid->next;
    mid->next = reverseLL(temp2);

    // step 3 : Compare the 2 halves
    LinkedListNode<int> *head1 = head;
    LinkedListNode<int> *head2 = mid->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // step 4 : reverse the reversed half back to normal(repeat step 2)
    temp2 = mid->next;
    mid->next = reverseLL(temp2);

    return true;
}

// Better : TC -> O(n) + O(n), SC -> O(n)
bool isPalindrom(LinkedListNode<int> *head) {
    
    vector<int> arr;
    LinkedListNode<int>* temp = head;
    while(temp != NULL){
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    int s = 0;
    int e = arr.size() - 1;

    while(s <= e){
        if(arr[s] != arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}