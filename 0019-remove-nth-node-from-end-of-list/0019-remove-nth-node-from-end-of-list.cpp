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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            counter++;
            temp=temp->next;
        }
        

        if(counter==n){
            return head->next;
        }

        temp=head;
        for(int i=1;i<counter-n;i++){
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        return head;
    }
};