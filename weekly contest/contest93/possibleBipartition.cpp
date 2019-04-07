vector<int> g[2001];
int id[2001];
//0 not chosen, 1 group 1, -1 group 2
class Solution {
public:

	bool DFS(int i){
		for(int j : g[i]){
			if(!id[j]){
				id[j] = -id[i]; //assign to opposite group
				if(!DFS(j))return false; //
			}
			else{
				if(id[i] == id[j])return false;
			}
		}
		return true;
	}	

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(int i = 0; i < N; i++)g[i].clear();
        for(vector<int> d : dislikes){
        	g[d[0]-1].push_back(d[1]-1);
        	g[d[1]-1].push_back(d[0]-1); //build up graph
        }
        fill(id,id+N,0);
        for(int i = 0; i < N; i++){
        	if(!id[i]){
        		id[i] = 1; //assign to group 1
        		if(!DFS(i))return false;
        	}
        }
        return true;
    }
};