//q1001
typedef pair<int,int> ii;
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& Q) {
        vector<int> ans;
		set<ii> s;
		map<int,int> row,col,diag,anti;
		for(vector<int> lamp : lamps){
			int x = lamp[0], y = lamp[1];
			s.insert({x,y});
			row[x]++;
			col[y]++;
			diag[x + y]++;
			anti[x - y]++;
		}
		for(vector<int> q : Q){
			int x = q[0], y = q[1];
			if(row[x] > 0 || col[y] > 0 || diag[x + y] > 0 || anti[x - y] > 0)ans.push_back(1);
			else ans.push_back(0);
			for(int i = -1; i < 2; i++){
				for(int j = -1; j < 2; j++){
					if(s.count({x+i,y+j})){ //is one of the illuminated lamp
						s.erase({x+i,y+j});
						row[x+i]--;
						col[y+j]--;
						diag[x+i+y+j]--;
						anti[x+i-y-j]--;
					}
				}
			}
		}        
        return ans;
    }
};