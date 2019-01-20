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
    
    int count(TreeNode* r){
        if(!r)return 0;
        return 1 + count(r->left) + count(r->right);
    }
    
    int sum(TreeNode* r){
        if(!r)return 0;
        return r->val + sum(r->left) + sum(r->right);
    }
    
    void compute(TreeNode* r, int& ans){
        if(!r)return;
        ans += abs(count(r->left)-sum(r->left));
        ans += abs(count(r->right)-sum(r->right));
        compute(r->left,ans);
        compute(r->right,ans);
    }
    
    int distributeCoins(TreeNode* r) {
        int ans = 0;
        compute(r,ans);
        return ans;
    }
};