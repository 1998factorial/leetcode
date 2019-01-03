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
    int rangeSumBST(TreeNode* n, int l, int r) {
        if(!n)return 0;
        if(n->val>=l && n->val<=r){
            return n->val + rangeSumBST(n->left,l,r) + rangeSumBST(n->right,l,r);
        }
        return rangeSumBST(n->left,l,r) + rangeSumBST(n->right,l,r);
    }
};