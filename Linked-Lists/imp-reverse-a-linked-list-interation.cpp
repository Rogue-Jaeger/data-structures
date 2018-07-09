// The use of 3 pointers is a must prev curr and next or 2 main pointers and 1 temp variable to point to next location
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL) return head; // line 1
        ListNode *prev = head, *curr = head->next , *next = NULL;

        /* Most important thing instead of putting line 1 we can also do prev = NULL and curr = pos of 1 then for 1 it will be curr->next = prev(which is NULL) */

        while(curr){
            next = curr->next; // address of 3 in next
            curr->next = prev; // point backwards
            prev = curr; // update previous
            curr = next; // update curr
        }

        head -> next = NULL;
        head = prev;

        return head;

    }
};

/* SECONDARY CODE IS :
public ListNode reverseList(ListNode head) {
    ListNode prev = null; // see here
    ListNode curr = head; // see here
    while (curr != null) {
        ListNode nextTemp = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}*/
