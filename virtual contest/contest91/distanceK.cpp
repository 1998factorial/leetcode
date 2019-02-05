/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> g[500];

class Solution {
public:
    
    void dfs(vector<int>& ans, int from, int dis, vector<bool>& seen){
        cout << from << '\n';
        if(!dis){
            ans.push_back(from);
            return;
        }
        int n = g[from].size();
        for(int i = 0; i < n; i++){
            int node = g[from][i];
            if(!seen[node]){
                seen[node] = true;
                dfs(ans,node,dis-1,seen);
            }
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        for(int i = 0; i < 500; i++)g[i].clear();
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int N = 0;
        while(!q.empty()){
            N++;
            TreeNode* n = q.front();
            q.pop();
            if(n->left){
                g[n->val].push_back(n->left->val);
                g[n->left->val].push_back(n->val);
                q.push(n->left);
            }
            if(n->right){
                g[n->val].push_back(n->right->val);
                g[n->right->val].push_back(n->val);
                q.push(n->right);
            }
        }
        vector<bool> seen(N);
        seen[target->val] = true;
        dfs(ans,target->val,K,seen);
        return ans;
    }
};