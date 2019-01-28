class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        for(int i = 0; i < n && i < K; i++)
            ans.push_back(points[i]);
        return ans;
    }
    
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
    }
    
};