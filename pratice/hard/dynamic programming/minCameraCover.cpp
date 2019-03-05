/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int INF = 1 << 10;
class Solution {
public:
    vector<int> solve(TreeNode* root){
        vector<int> dp(3);
        if(!root){
            dp[0] = INF,dp[1] = 0, dp[2] = INF;
            return dp;
        }
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        dp[0] = 1 + min(l[0],min(l[1],l[2])) + min(r[0],min(r[1],r[2]));
        dp[1] = min(l[0]+r[0],min(l[0]+r[1],l[1]+r[0]));
        dp[2] = l[1]+r[1];
        return dp;
    }
    
    int minCameraCover(TreeNode* root) {
        vector<int> dp = solve(root);
        return min(dp[0],dp[1]);
    }
};