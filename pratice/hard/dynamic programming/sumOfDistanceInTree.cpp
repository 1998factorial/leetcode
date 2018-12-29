//Q834
//N could be really large so we cannot use floyde
//if we use dfs on every node it will be O(n^2) which is too slow
//so we should use dp
const int N = 1e4 + 10;
vector<int> a[N]; //graph list
int dp0[N],dp1[N]; //dp0[0] = numebr of nodes in subtree rooted at 0.
//dp1[0] tree sum at root 0
void DFS(int u, int parent){
    dp0[u] = 1;
    dp1[u] = 0;
    for(auto& v : a[u]){
        if(v == parent)continue;
        DFS(v,u);
        dp0[u] += dp0[v]; // + # nodes in subtree(v)
        dp1[u] += dp1[v] + dp0[v]; //sum(v) + # nodes in subtree(v), coz edge(u,v) is used that many of times
    }
}
void DFS2(vector<int>& ans, int u, int parent, int n){
    for(auto& v : a[u]){
        if(v == parent)continue;
        ans[v] = ans[u] - 2*dp0[v] + n; // easy observation
        DFS2(ans,v,u,n);
    }
}
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) a[i].clear();
        for(int i = 0; i < n-1; ++i) a[edges[i][0]].push_back(edges[i][1]) , a[edges[i][1]].push_back(edges[i][0]);
        //get graph list
        DFS(0,-1); //do on node 0
        ans[0] = dp1[0]; //got answer for node 0
        //we use ans[0] to solve the rest
        DFS2(ans,0,-1,n);
        return ans;
    }
};