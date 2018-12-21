/*
Given a binary tree,
find its minimum depth.

The minimum depth is the number of nodes along the 
shortest path from the root node down to the nearest leaf node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) //empty tree
            return 1;
        if(!root->left and !root->right) //leaf
            return 1;
        if(!root->left) //no right
        	return 1 + minDepth(root->left);
        if(!root->right) //no left
        	return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};