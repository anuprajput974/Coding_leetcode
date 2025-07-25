/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        // ListNode* temp=head;
       while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* entry=head;
               while(entry!=slow){
                  entry=entry->next;
                  slow=slow->next;
               }
               return entry;
            }
            
            
       }
       return nullptr;

        
        
    }
};