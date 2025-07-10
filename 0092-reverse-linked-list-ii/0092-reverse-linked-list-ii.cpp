/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;

        for(int i=1;i<left;i++){
            prev=prev->next;

        }

        ListNode* curr=prev->next;
        ListNode* then=curr->next;

        for(int i=0;i<right-left;i++){
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = curr->next;
        }
        return dummy->next;


        
    }
};