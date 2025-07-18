/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);

        while(!qu.empty()){
            TreeNode* first=qu.front();
            qu.pop();
            TreeNode* second=qu.front();
            qu.pop();

             if(first==nullptr && second==nullptr){
                continue;
             }
                else if
                (first==nullptr || second==nullptr ||first->val!=second->val)
                {
                    return false;
                } 
        
        
        qu.push(first->left);
        qu.push(second->left);
        qu.push(first->right);
        qu.push(second->right);
            
        }
        
        return true;
    }
     
};