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
    bool isCompleteTree(TreeNode* n) {
    	queue<TreeNode*> Q;
    	Q.push(n);//start with node n
    	while(!Q.empty()){//while queue is not empty
    		TreeNode* m = Q.front();
    		Q.pop();
    		if(m->left  and m->right ){
    			Q.push(m->left);
    			Q.push(m->right);
    		}
    		if(!m->left and m->right)
    			return false;
    		if((m->left and !m->right)or(!m->left and !m->right)){
    			//we find the end point
    			if(m->left)Q.push(m->left);//don't forget to put m->left into queue
    			bool all_ends = true;
    			while(!Q.empty()){
    				TreeNode* p = Q.front();
    				Q.pop();
    				if(p->left or p->right )
    					all_ends = false;
    			}
    			if(!all_ends)
    				return false;
    		}
    	}
    	return true;
    }
};

//bfs