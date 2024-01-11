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
    int maxDiff(TreeNode* node, int maxVal, int minVal){
        if(node == nullptr) return maxVal - minVal;

        maxVal = max(maxVal, node->val);
        minVal = min(minVal, node->val);
        int maxLeftDiff = maxDiff(node->left, maxVal, minVal);
        int maxRightDiff = maxDiff(node->right, maxVal, minVal);
        
        return max(maxLeftDiff, maxRightDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) return 0;
        return maxDiff(root, root->val, root->val);
    }
};