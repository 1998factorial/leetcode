class Solution {
public:
    
    int find(vector<int>& a, int i){
        if(i != a[i])a[i] = find(a,a[i]);
        return a[i];
    }
    
    void connect(vector<int>& a, int i, int j){
        if(i > j)swap(i,j);
        a[find(a,i)] = find(a,j);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        //left 0, down 1, right 2, up 3
        int ans = 0, n = grid.size();
        int N = 4*n*n;
        vector<int> a(N);
        for(int i = 0; i < N; i++)a[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cur = 4*(i*n + j);
                int right = 4*(i*n + j + 1);
                int down = 4*((i+1)*n + j) + 3;
                if(grid[i][j] == ' '){
                    connect(a,cur,cur+1);
                    connect(a,cur,cur+2);
                    connect(a,cur,cur+3);
                    if(i < n-1)connect(a,cur+1,down);//connect cur's down with down
                    if(j < n-1)connect(a,cur+2,right);//connect cur's right with right
                }
                else if(grid[i][j] == '/'){
                    connect(a,cur,cur+3);
                    connect(a,cur+1,cur+2);
                    if(i < n-1)connect(a,cur+1,down);//connect cur's down with down
                    if(j < n-1)connect(a,cur+2,right);//connect cur's right with right
                }
                else{
                    connect(a,cur,cur+1);
                    connect(a,cur+2,cur+3);
                    if(i < n-1)connect(a,cur+1,down);//connect cur's down with down
                    if(j < n-1)connect(a,cur+2,right);//connect cur's right with right
                }
            }
        }
        for(int i = 0; i < N; i++)
            ans += (i == find(a,i));
        return ans;
    }
};