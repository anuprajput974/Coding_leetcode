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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp1=head;


       
        while(temp1!=nullptr){
           ListNode* prev=temp1;
           ListNode* temp2=temp1->next;

            while(temp2!=nullptr){
                if(temp1->val==temp2->val){
                    prev->next=temp2->next;
                    delete temp2;
                    temp2=prev->next;
                }else{
                    prev=temp2;
                    temp2=temp2->next;
                }
                
            }
            temp1=temp1->next;
        }
        return head;
        
    }
};