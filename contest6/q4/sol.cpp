class Solution {
	int nK = 0;
	bool keys[6] = {false,false,false,false,false,false};

public:

	int dfs(vector<string>& G, int x, int y){
		
	}

	bool isKey(char x){
		return x=='a' or x=='b' or x=='c' or x=='d' or x=='e' or x=='f';
	}
	bool isLock(char x){
		return x=='A' or x=='B' or x=='C' or x=='D' or x=='E' or x=='F';
	}

    int shortestPathAllKeys(vector<string>& G) {
    	int n = G.size();
    	if(!n)return -1;
    	int m = G[0].size();
    	int x = 0, y = 0;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		if(isKey(G[i][j]))++nK; //get number of keys
        		if(G[i][j] == '@'){
        			x = i;
        			y = j;
        		}
        	}
        }
        //do dfs
        int path = dfs(G,x,y);
        return path;
    }
};