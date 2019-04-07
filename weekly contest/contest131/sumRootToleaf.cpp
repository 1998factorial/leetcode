/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long ll;
ll mod = 1e9+7;
class Solution {
public:
    
    vector<string> solve(TreeNode* n){
        if(!n)return {};
        vector<string> l = solve(n->left);
        vector<string> r = solve(n->right);
        vector<string> ret;
        if(l.size() == 0 && r.size() == 0){
            if(n->val)ret.push_back("1");
            else ret.push_back("0");
            return ret;
        }
        if(l.size())for(string x : l){
            string t = x;
            if(n->val)t += '1';
            else t += '0';
            ret.push_back(t);
        }
        if(r.size())for(string x : r){
            string t = x;
            if(n->val)t += '1';
            else t += '0';
            ret.push_back(t);
        }
        return ret;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<string> path = solve(root);
        ll ret = 0;
        int m = path.size();
        for(int i = 0; i < m; i++){
            int len = path[i].size();
            ll add = 0;
            for(int j = len-1; j >= 0; j--)add = (add*2 + (path[i][j]-'0') + mod) % mod;
            ret = (ret + add + mod ) % mod;
        }
        return ret;
    }
};