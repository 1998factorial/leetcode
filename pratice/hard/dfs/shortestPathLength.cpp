/*
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
	we use dfs approach
*/
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& G) {
    	int n = G.size();
    	if(!n)return 0;
    	

    }
};














