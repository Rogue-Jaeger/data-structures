//https://leetcode.com/problems/reverse-linked-list/description/

ListNode * p = NULL; // can declare a global variable

ListNode * reverse( ListNode * head ){
    if(head == NULL) return head;
    if(head->next == NULL){
        p = head;
        return p;
    }

    p = reverse( head -> next );
    ListNode * next = head -> next;
    next -> next = head;
    head -> next = NULL; // so that first node will point to NULL at the end
    return p;
}

class Solution {
public: ListNode * reverseList(ListNode* head) {
        return reverse(head);
    }
};
