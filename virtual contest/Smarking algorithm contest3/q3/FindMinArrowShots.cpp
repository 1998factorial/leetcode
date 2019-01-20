class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& p) {
        int ans = 0, n = p.size(),num = 0,i = 0;
        sort(p.begin(),p.end(),cmp);
        vector<bool> s(n,false);
        while(num < n){
            if(i >= n)break;
            ++ans;
            int m = p[i].second;
            for(int j = 0; j < n; j++){
                if(s[j])continue;
                if(p[j].first <= m){
                    s[j] = true, ++num;
                }
            }
            while(i < n && s[i])++i;
        }
        return ans;
    }
    
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
    
};

//a faster solution

class Solution {
public:
    
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.second < b.second)return true;
        else if(a.second == b.second)return a.first < b.first;
        return false;
    }
    
    int findMinArrowShots(vector<pair<int, int>>& p) {
        int ans = 0, n = p.size();
        sort(p.begin(),p.end(),cmp);
        int i = 0;
        while(i < n){
            ++ans;
            int j = i+1;
            while(j < n && p[j].first <= p[i].second)++j;
            i = j;
        }
        return ans;
    }
};