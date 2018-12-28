/*
Question 847


An undirected, 
connected graph of N nodes (labeled 0, 1, 2, ..., N-1) 
is given as graph.

graph.length = N, and j != i is in the list graph[i] exactly once, 
if and only if nodes i and j are connected.

Return the length of the shortest path that visits every node. 
You may start and stop at any node, you may revisit nodes multiple times, 
and you may reuse edges.

Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
*/
/*
	此题目的难点在于图中的每一个节点可以被重复访问
	we use dynamic programming to approach

	dp[i][s] = "minimal distance of state s ending at node i"
	s = 101 in binary means we have visited node 0,2

	eg.
		dp[101][0] = min(dp[101][0],dp[100][1]+dis[1][0])
	dis[i][j] = "minimal distance from i to j"
*/

class Solution {
public:

	void floyd(vector<vector<int>>& G, vector<vector<int>>& dis){
		int n = G.size();
		for(int i = 0; i < n; i++)
			dis[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < G[i].size(); j++)
					dis[i][G[i][j]] = 1;
		
		for(int i = 0; i < n; i++) //O(n^3)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(k!=i && k!= j)
						dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	}

    int shortestPathLength(vector<vector<int>>& G) {
    	int N = G.size();
    	if(N <= 2)return N-1;
    	vector<vector<int>> dp((1 << N),vector<int>(N, 1 << 20)); //dp[state][node]
    	vector<vector<int>> dis(N,vector<int>(N,1 << 20));
    	floyd(G,dis); //Floyd algorithm
    	int end_state = (1 << N) - 1;
    	for(int i = 0; i < N; i++)dp[1 << i][i] = 0;
    	//dp[101][0] = min(dp[101][0],dp[100][1]+dis[1][0])
    	for(int state = 1; state < (1 << N); state++){
    		for(int i = 0; i < N; i++){
    			if(state & (1 << i)){ //we can only do this when i is in our state
    				for(int j = 0; j < N; j++){
    					dp[state][i] = min(dp[state][i],dp[state^(1 << i)][j]+dis[j][i]);
    				}
    			}
    		}
    	}

    	int ret = 1 << 20;
    	for(int i = 0; i < N; i++)
    		ret = min(ret,dp[end_state][i]);
    	return ret;

    }
};














