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


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>t1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=nullptr){
            t1.push_back(temp1->val);
            temp1=temp1->next;

        }
        while(temp2!=nullptr){
            t1.push_back(temp2->val);
            temp2=temp2->next;

        }
        sort(t1.begin(),t1.end());
        
        if (t1.empty()) return nullptr;

        ListNode* dummy=new ListNode(t1[0]);
        ListNode* curr=dummy;
        for(int i=1;i<t1.size();i++){
            curr->next=new ListNode(t1[i]);
            curr=curr->next;
        }
        return dummy;

        
    }
};