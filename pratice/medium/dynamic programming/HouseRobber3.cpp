/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
 */
class Solution {
public:
    
    int rob(TreeNode* n) {
    	vector<int> dp = find(n);
    	return max(dp[0],dp[1]);
    }

    vector<int> find(TreeNode* n){
    	vector<int> dp(2,0); 
    	if(!n)return dp;
    	//dp[0] = "maximal money from leaves to root if i don't rob n"
    	//dp[1] = "maximal money from leaves to root if i rob n"
    	vector<int> left = find(n->left);
    	vector<int> right = find(n->right);

    	dp[0] = max(left[0],left[1])+max(right[0],right[1]);
    	dp[1] = n->val + left[0] + right[0];
    	return dp;
    }

};