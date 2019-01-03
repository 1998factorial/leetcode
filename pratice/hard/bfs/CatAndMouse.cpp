//Q913
/*
rules: 
	1.Mouse starts at node 1 and goes first, 
	Cat starts at node 2 and goes second, 
	and there is a Hole at node 0.
	2.During each player's turn, 
	they must travel along one edge of the graph that meets where they are.  
	For example, if the Mouse is at node 1, 
	it must travel to any node in graph[1].
	3.Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
	4.Then, the game can end in 3 ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated 
(ie. the players are in the same position as a previous turn, 
and it is the same player's turn to move), the game is a draw.

Note:

3 <= graph.length <= 50
It is guaranteed that graph[1] is non-empty.
It is guaranteed that graph[2] contains a non-zero element. 
*/
//mouse need to reach hole before cat reaches mouse
//cat need to reach where mouse is before mouse reaches hole
class Solution {
public:
    int catMouseGame(vector<vector<int>>& G){
        //cat at 2, mouse at 1



    }// 2 if mouse wins, 1 if cat wins, 0 if draw
};


