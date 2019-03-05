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
    vector<int> getVec(TreeNode* n){
        vector<int> ret;
        if(!n)return ret;
        vector<int> l = getVec(n->left);
        vector<int> r = getVec(n->right);
        for(int i : l)ret.push_back(i);
        ret.push_back(n->val);
        for(int i : r)ret.push_back(i);
        return ret;
    }
    
    TreeNode* gen(vector<int>& v, int i, int j){
        if(i > j)return NULL;
        int mx = -10000, index = -1;
        for(int k = i; k <= j; k++){
            if(mx < v[k]){
                mx = v[k],index = k;
            }
        }
        if(index == -1)return NULL;
        TreeNode* ret = new TreeNode(v[index]);
        ret->left = gen(v,i,index-1);
        ret->right = gen(v,index+1,j);
        return ret;
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        vector<int> ret;
        ret = getVec(root);
        ret.push_back(val);
        return gen(ret,0,ret.size()-1);
    }
};