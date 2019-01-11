vector<int> a[500];
class Solution {
public:

	int dfs(vector<int>& quiet, int u, vector<int>& ans){
		int cur_min = quiet[u],n = a[u].size(),ret = u;
		for(int i = 0; i < n; i++){ //for all person that are richer than me
			int v = a[u][i];
			if(ans[v] != -1){
				if(cur_min > quiet[ans[v]]){
					cur_min = quiet[ans[v]];
					ret = ans[v];
				}
				continue;
			}
			int next = dfs(quiet,v,ans);
			if(quiet[next] < cur_min){
				cur_min = quiet[next];
				ret = next;
			}
		}
		return ret;
	}

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    	int n = quiet.size(), m = richer.size();
    	vector<int> ans(n,-1);
    	for(int i = 0; i < n; i++)a[i].clear();
    	for(int i = 0; i < m; i++)
    		a[richer[i][1]].push_back(richer[i][0]);
    	for(int i = 0; i < n; i++){
    		ans[i] = dfs(quiet,i,ans);
    	}
    	return ans;
    }
};
    