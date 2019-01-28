//q959
//each grid has 4 directions, up, down, left and right
//if grid is " " then all 4 are connected
//if grid is "\" or "/" then we will have 2 pairs
//a union find solution
class Solution {
public:

    int root(vector<int>& a, int i){
        if(a[i] != i)a[i] = root(a,a[i]); //find i's ancestor
        return a[i];
    }

    void connect(vector<int>& a, int i, int j){
        if(i > j)swap(i,j);
        a[root(a,j)] = root(a,i); //set j's ancestor to be i's ancestor
    }

    int regionsBySlashes(vector<string>& grid) {
        int ans = 0, n = grid.size(), N = 4*n*n;
        //left 0, down 1, right 2, up 3
        vector<int> a(N);
        for(int i = 0; i < N; i++)a[i] = i;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int cur = 4 * (i * n + j);// current grid map to vector
                int right = 4 * (i * n + j + 1);//current's right next map to vector
                int down = 4 * ((i+1) * n + j) + 3;//current's down next map to vector
                if(grid[i][j] == ' '){
                    //connect all 4 directions
                    connect(a,cur,cur+1);
                    connect(a,cur,cur+2);
                    connect(a,cur,cur+3);
                    if(j < n-1)connect(a,cur+2,right);//connect cur's right to right
                    if(i < n-1)connect(a,cur+1,down);//connect cur's down to down
                }
                else if(grid[i][j] == '/'){
                    connect(a,cur,cur+3);
                    connect(a,cur+1,cur+2);
                    if(j < n-1)connect(a,cur+2,right);
                    if(i < n-1)connect(a,cur+1,down);
                }
                else{ // grid[i][j] == '\'
                    connect(a,cur,cur+1);
                    connect(a,cur+2,cur+3);
                    if(j < n-1)connect(a,cur+2,right);
                    if(i < n-1)connect(a,cur+1,down);
                }
            }
        }
        for(int i = 0; i < N; i++)
            ans += (i == root(a,i));        
        return ans;
    }
};