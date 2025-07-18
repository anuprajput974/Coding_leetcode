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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> leftqueue;
        queue<TreeNode*> rightqueue;

        leftqueue.push(root->left);
        rightqueue.push(root->right);

       
        while(!leftqueue.empty() && !rightqueue.empty()){
             TreeNode* leftNode=leftqueue.front();
             leftqueue.pop();
             TreeNode* rightNode=rightqueue.front();
             rightqueue.pop();

             if(leftNode==nullptr && rightNode==nullptr) continue;

            if(leftNode==nullptr || rightNode==nullptr || leftNode->val!=rightNode->val){
                return false;

            }
            leftqueue.push(leftNode->left);
            rightqueue.push(rightNode->right);
            leftqueue.push(leftNode->right);
            rightqueue.push(rightNode->left);

        }
        return true;
        
    }
};