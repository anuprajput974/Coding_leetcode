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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int length = 0;
        ListNode* temp = head;
        
        // Step 1: Find the length of the linked list
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Step 2: Compute base size and extra nodes
        int baseSize = length / k;      // Minimum nodes in each part
        int extraNodes = length % k;    // Extra nodes to distribute
        
        ListNode* current = head;
        ListNode* prev = nullptr;

        // Step 3: Split the list into k parts
        for (int i = 0; i < k; i++) {
            result[i] = current;
            int partSize = baseSize + (extraNodes > 0 ? 1 : 0); // Add an extra node if extraNodes > 0
            extraNodes--;

            // Move `current` `partSize` steps forward
            for (int j = 0; j < partSize; j++) {
                if (current) {
                    prev = current;
                    current = current->next;
                }
            }
            // Cut the current part from the rest of the list
            if (prev) {
                prev->next = nullptr;
            }
        }

        return result;
    
        
    }
};