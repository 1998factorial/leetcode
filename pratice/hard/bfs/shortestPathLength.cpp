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
	we use bfs to approach
*/
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& G) {
    	int N = G.size(),steps = 0;
    	if(N<=2)return N-1;
        vector<vector<bool>> seen(N,vector<bool>(1 << N, false));
        int end_state = (1 << N) - 1;
        queue<pair<int,int>> states; //<node,state>
        for(int i = 0; i < N; i++)
            states.push({i,1 << i});
        while(!states.empty()){
            int M = states.size();
            ++steps; //expand to next
            for(int i = 0; i < M; i++){
                pair<int,int> p = states.front();
                states.pop();
                int cur_node = p.first;
                int cur_state = p.second;
                for(int j = 0; j < G[cur_node].size(); j++){
                    int next_node = G[cur_node][j];
                    int next_state = cur_state | (1 << next_node);
                    if(next_state == end_state)return steps;
                    if(!seen[next_node][next_state]){
                        seen[next_node][next_state] = true;
                        states.push({next_node,next_state});
                    }
                }
            }
        }
        return -1;
    }
};














