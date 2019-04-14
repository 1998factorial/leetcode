/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> d[1005];

class Solution {
public:
    int n;
    TreeNode* recoverFromPreorder(string s) {
        for(int i = 0; i < 1005; i++)d[i].clear();
        n = s.size();
        if(!n)return NULL;
        int i = 0, j = 0,cnt = 0,mx_h = -1;
        while(i < n){
            cnt = 0;
            while(i < n && s[i] == '-')cnt++,i++; //copute depth
            int num = 0;
            while(i < n && s[i] <= '9' && s[i] >= '0')num = num*10 + s[i]-'0',i++; //compute val
            mx_h = max(mx_h,cnt);
            TreeNode *cur = new TreeNode(num);    
            cur->left = cur->right = NULL;
            if(cnt > 0){
                if(!d[cnt-1].back()->left)d[cnt-1].back()->left = cur;
                else d[cnt-1].back()->right = cur;
            }
            d[cnt].push_back(cur);
        }
        return d[0].back();
    }
};