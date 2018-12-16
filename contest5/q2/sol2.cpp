class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
  	//find cycle
    //observe that 14 is a cycle
    	vector<int> next(8,0);//cells size == 8
        for(int j = 0; j < 8; j++)next[j] = cells[j];
    	for(int i = 1; i <= (N-1)%14 + 1; i++){ //pattern repeats every 14 cycles
    		for(int j = 0; j < 8; j++){
    			if(j == 0 or j == 7)
    				next[j] = 0;
    			else if((cells[j-1] and cells[j+1])or(!cells[j-1] and !cells[j+1]))
    				next[j] = 1;
    			else
    				next[j] = 0;
    		}for(int j = 0; j < 8; j++)cells[j] = next[j];
    	}
    	return next;
  	}
};