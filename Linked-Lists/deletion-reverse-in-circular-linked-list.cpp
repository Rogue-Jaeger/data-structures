// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

void deleteNode(struct Node *head, int key)
{
    Node * prev = NULL, *curr = head;
    while(curr->data != key){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    free(curr);

    //reverse(head);
}
/* Function to reverse the linked list */
static void reverse(struct Node* head)
{
    Node *curr = head , *prev = NULL;
    while(curr->next != head){
        curr -> next = prev;
        prev = curr;
        curr = curr -> next;
    }

    curr -> next = prev;
    head -> next = curr;
}
