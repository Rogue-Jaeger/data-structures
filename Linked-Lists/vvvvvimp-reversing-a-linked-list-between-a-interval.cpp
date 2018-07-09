// https://leetcode.com/problems/reverse-linked-list-ii/description/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//....... we will always need a dummy cause there is a difference in updating a pointer to a head and updating pointer to a node from a node
//....... e.g head is updated as head = updator and node is updated as node->next = updator

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode * dummy = new ListNode(0);  // see how new node is declared
        dummy->next = head;

        int count = 0;

        ListNode * curr = dummy , *prev = NULL , *initial = NULL;

        while(curr){
            if( count > m && count <= n){
                ListNode * next = curr->next;
                curr -> next = initial->next;
                prev -> next = next;
                initial -> next = curr;
                curr = next;
                count++;
            }
            else{
                if(count == m){
                    initial = prev;
                }
                prev = curr;
                curr = curr->next;
                count++;
            }

        }

        return dummy -> next;


    }
};
