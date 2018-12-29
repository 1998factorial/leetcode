//Q785
//we use union find to check if a graph is bipartite
class Solution {
public:

	int find(vector<int>& p, int x){
		return p[x] == x ? x : find(p,p[x]);
	}
	//maintain a node -> id relation
    bool isBipartite(vector<vector<int>>& g) {
		int N = g.size();
		if(!N)return true;
		if(N == 1 && !g[0].size())return true;
		vector<int> p(N);
		for(int i = 0; i < N; i++)
			p[i] = i;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < g[i].size(); j++){
				int k = g[i][j];
				if(find(p,i) == find(p,k))return false;
				int u = find(p,g[i][0]);
				int v = find(p,g[i][j]);
				if(u != v)p[v] = u;
			}
		}
		return true;
    }
};