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
    bool isCompleteTree(TreeNode* r) {
        if(!r)return true;
        queue<TreeNode*> q;
        q.push(r);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n)q.push(n->left),q.push(n->right);
            else{
                while(!q.empty()){
                    TreeNode* m = q.front();
                    q.pop();
                    if(m)return false;
                }
            }
        }
        return true;
    }
};