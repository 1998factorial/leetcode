/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//preorder => cur left right
class Solution {
public:

	void pre(TreeNode* n, vector<int>& w){
		if(!n)return;
		w.push_back(n->val);
		pre(n->left,w);
		pre(n->right,w);
	}

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        vector<int> ans,w;
        int n = v.size();
        pre(root,w);
        int m = w.size();
        //for(int i = 0; i < n; i++)
        //	printf("%d ",w[i]);
        return ans;
    }
};