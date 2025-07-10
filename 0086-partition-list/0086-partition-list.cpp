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
    ListNode* partition(ListNode* head, int x) {
       
        ListNode* left=new ListNode(-1);
        ListNode* temp1=left;
        ListNode* right=new ListNode(-1);
        ListNode* temp2=right;

        

        while(head!=nullptr){
            if(head->val<x){
                temp1->next=new ListNode(head->val);
                temp1=temp1->next;
            }
            else{
                temp2->next=new ListNode(head->val);
                temp2=temp2->next;
            }
            head=head->next;


        }
        temp1->next=right->next;

        return left->next;
        
    }
};