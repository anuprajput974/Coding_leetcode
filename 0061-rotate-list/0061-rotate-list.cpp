class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head) return nullptr;
        int n = 1;
        ListNode* temp = head;
        while (temp->next) {
            n++;
            temp = temp->next;
        }
        k %= n;
        temp->next = head;
        for (int i = 0; i < n - k; i++) temp = temp->next;
        ListNode* new_head = temp->next;
        temp->next = nullptr;
        return new_head;
        
    }
};
