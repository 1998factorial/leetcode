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
    int ret;
    vector<int> a;
    
    void DFS(TreeNode* root){
        if(!root)return;
        for(int i : a)ret = max(ret,abs(root->val - i));
        a.push_back(root->val);
        DFS(root->left);
        DFS(root->right);
        a.pop_back();
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        ret = -1;
        a.clear();
        DFS(root);
        return ret;
    }
};