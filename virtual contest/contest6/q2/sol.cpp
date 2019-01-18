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
    int height(TreeNode* root){
        if(!root)return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    TreeNode* find(TreeNode* n, int h){
    	if(!n)return NULL;
    	if(h == 1)return n;
    	TreeNode* l = find(n->left,h-1);
    	TreeNode* r = find(n->right,h-1);
    	if(!l)return r;
    	if(!r)return l;
    	return n;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    	int h = height(root);
    	return find(root,h);
    }
};