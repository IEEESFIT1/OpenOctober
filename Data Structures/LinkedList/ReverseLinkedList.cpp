/*
Given a linked list of N nodes. The task is to reverse this list.Return new head after reversing the list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
*/

struct Node* reverseList(struct Node *head)
{
        struct Node *current = head;
        struct Node *prev = NULL,*next=NULL;
        while(current != NULL)
        {
            next = current->next; //storing
            current->next = prev;  //reverse current node
            
            prev = current;
            current = next; 
        }
        head= prev;
        return head;
}
