//q850
//x1,y1,x2,y2
typedef long long int64;
int64 mod = 1e9+7;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> X,Y;
        for(int i = 0; i < n; i++){
            X.push_back(a[i][0]);
            Y.push_back(a[i][1]);
            X.push_back(a[i][2]);
            Y.push_back(a[i][3]);
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        //sort + remove duplication
        int x = X.size(),y = Y.size();
        vector<vector<bool>> cover(x,vector<bool>(y));
        for(int i = 0; i < n; i++){
            int x1,x2,y1,y2;
            x1 = lower_bound(X.begin(),X.end(),a[i][0]) - X.begin();
            x2 = lower_bound(X.begin(),X.end(),a[i][2]) - X.begin();
            y1 = lower_bound(Y.begin(),Y.end(),a[i][1]) - Y.begin();
            y2 = lower_bound(Y.begin(),Y.end(),a[i][3]) - Y.begin();
            for(int j = x1; j < x2; j++)
                for(int k = y1; k < y2; k++)
                    cover[j][k] = true;
        }
        int ans = 0;
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                if(cover[i][j])
                    ans = (ans + (int64)(X[i+1]-X[i])*(Y[j+1]-Y[j])) % mod;
        return ans;
    }
};