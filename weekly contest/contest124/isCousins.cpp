/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//soln 1
class Solution {
public:
    
    int f(TreeNode* n, int x){
        if(!n)return 10000;
        if(n->val == x)return 0;
        return 1 + min(f(n->left,x),f(n->right,x));
    }
    
    bool g(TreeNode* r, int x, int y){
        if(!r)return true;
        if(r->left && r->right){
            if(r->left->val == x && r->right->val == y)return false;
            if(r->left->val == y && r->right->val == x)return false;
        }
        bool L = g(r->left,x,y), R = g(r->right,x,y);
        return L && R;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(f(root,x) != f(root,y))return false;
        return g(root,x,y);
    }
};


//soln 2
class Solution {
public:
    
    void solve(TreeNode* n, int d, map<int,int>& father, map<int,int>& depth){
        if(!n)return;
        depth[n->val] = d;
        if(n->left)father[n->left->val] = n->val;
        if(n->right)father[n->right->val] = n->val;
        solve(n->left,d+1,father,depth);
        solve(n->right,d+1,father,depth);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        map<int,int> father, depth;
        solve(root,0,father, depth);
        return depth[x] == depth[y] && father[x] != father[y];
    }
};

