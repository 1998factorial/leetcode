//q407
//向内合围！
const int N = 111 * 111;
bool v[N];
typedef pair<int,int> ii;
class Solution {
public:
    int n,m,ret;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int trapRainWater(vector<vector<int>>& h) {
        n = h.size(),ret = 0;
        if(!n)return 0;
        m = h[0].size();
        memset(v,false,sizeof(v));
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        //get the boundaries
        for(int i = 0; i < m; i++){
            pq.push({h[0][i],i}),pq.push({h[n-1][i],(n-1)*m+i}),v[i] = true,v[(n-1)*m+i] = true;
        }
        for(int i = 0; i < n; i++){
            if(i == 0 || i == n-1)continue;
            pq.push({h[i][0],i*m}),pq.push({h[i][m-1],i*m+m-1}),v[i*m] = true,v[i*m+m-1] = true;       
        }
        //shrink 
        while(!pq.empty()){
            ii s = pq.top();
            pq.pop();
            int i = s.second/m , j = s.second % m;
            for(int k = 0; k < 4; k++){
                int u = i+dx[k], w = j+dy[k];
                if(u < 0 || u >= n || w < 0 || w >= m || v[u*m+w])continue;
                v[u*m+w] = true;
                ret += max(0,s.first - h[u][w]);
                pq.push({max(h[u][w],s.first),u*m+w});
            }
        }
        return ret;
    }
};

