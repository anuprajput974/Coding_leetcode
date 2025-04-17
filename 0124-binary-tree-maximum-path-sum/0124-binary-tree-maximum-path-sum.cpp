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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    // Helper function to calculate the max gain from current node
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Compute the maximum path sum for left and right children
        // If the result is negative, discard by taking 0
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // Path sum using current node as the root of the path
        int currentPath = node->val + leftGain + rightGain;

        // Update the global max path sum if needed
        maxSum = max(maxSum, currentPath);

        // Return the maximum sum of a path extending upwards to the parent
        return node->val + max(leftGain, rightGain);
    }
};