class Solution {
public:
    int oddEvenJumps(vector<int>& a) {
        int n = a.size(), ans = 0;
        if(!n)return 0;
        vector<bool> odd(n,false), even(n,false);
        odd[n-1] = even[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            if(a[i] == a[i+1]){
                odd[i] = even[i+1];
                even[i] = odd[i+1];
            }
            else{
                vector<vector<int>> greater,smaller;
                int j = i+1;
                for(; j < n; j++){
                    if(a[j] >= a[i])greater.push_back({a[j],j});
                    if(a[j] <= a[i])smaller.push_back({a[j],j});
                }
                sort(greater.begin(),greater.end(),cmp);
                sort(smaller.begin(),smaller.end(),cmp);
                int x = greater.size(),y = smaller.size();
                if(x)odd[i] = even[greater[0][1]];//,printf("odd[%d] = %d\n",i,greater[0][0]);
                if(y)even[i] = odd[smaller[y-1][1]];//,printf("even[%d] = %d\n",i,smaller[y-1][0]);
            }
        }
        for(int i = 0; i < n; i++)ans += odd[i];
        return ans;
    }

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

};