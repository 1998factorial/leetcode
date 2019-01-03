class Solution {
public:
    int minAreaRect(vector<vector<int>>& p) {
        int ans = 1 << 28, n = p.size();
        bool s = false;
        sort(p.begin(),p.end(),cmp);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(p[i][1] != p[j][1])continue;
                //same height
                int width = p[j][0] - p[i][0];
                vector<vector<int>> q; //points match p[i] or p[j]
                for(int k = 0; k < n; k++){
                    if(p[k][0] == p[i][0] || p[k][0] == p[j][0]){
                        q.push_back(p[k]);
                    }
                }
                int a = 0,b = 0,height = 1 << 20,m = q.size();
                for(int x = 0; x < m; x++){
                    if(q[x][0] == p[i][0]){
                        //find q[] that matches p[j][0]
                        if(q[x][1] > p[i][1]){
                            height = q[x][1]-p[i][1];
                            for(int y = 0; y < m; y++){
                                if(q[y][0] == p[j][0] && q[y][1] - p[j][1] == height){
                                    s = true;
                                    ans = min(width*height,ans);
                                }
                            }
                        }
                        else if(q[x][1] < p[i][1]){
                            height = p[i][1]-q[x][1];
                            for(int y = 0; y < m; y++){
                                if(q[y][0] == p[j][0] && p[j][1] - q[y][1] == height){
                                    s = true;
                                    ans = min(width*height,ans);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!s)return 0;
        return ans;
    }
    
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
};