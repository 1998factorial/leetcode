/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
dp[0]="min #(cam): node has camera and subtree is under monitor"
dp[1]="min #(cam): node has no camera and subtree is under monitor"
dp[2]="min #(cam): node has no camera and subtree is not under monitor"
*/


class Solution {
public:
const int M = 1e8;

	vector<int> check(TreeNode* n){
		vector<int> dp = {M,0,0};
		if(!n)return dp;
		vector<int> l = check(n->left);
		vector<int> r = check(n->right);
		dp[0] = 1 + min(min(l[0],l[1]),l[2]) + min(min(r[0],r[1]),r[2]);
		//n has cam & cover sub 
		dp[1] = min(min(l[0]+r[0],l[0]+r[1]),l[1]+r[0]);
		//n has no cam & cover sub and n
		dp[2] = l[1] + r[1];
		//n has no cam & not cover n but its sub
		printf("%d,%d,%d\n",dp[0],dp[1],dp[2]);
		return dp;
	}

    int minCameraCover(TreeNode* n) {
        //Each camera at a node can monitor its parent, itself, and its immediate children.
    	vector<int> ans = check(n);
    	return min(ans[0],ans[1]); //we need the root to be monitored
    }
};



