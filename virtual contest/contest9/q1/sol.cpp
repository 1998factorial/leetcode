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

	bool f(TreeNode* n, int v){
		if(!n)return true;
		if(n->val != v)return false;
		return f(n->left,v) && f(n->right,v);
	}

    bool isUnivalTree(TreeNode* root) {
    	if(!root)return true;
        return f(root,root->val);
    }
};