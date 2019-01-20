class Solution {
public:
    int minMoves(vector<int>& a) {
        int steps = 0, n = a.size();
        if(n < 2)return 0;
        int h = 1 << 31 , l = (1 << 31)-1, h_i = -1;
        while(h != l){
            h = 1 << 31 , l = (1 << 31)-1, h_i = -1;
            for(int i = 0; i < n; i++){
                if(h < a[i])
                    h = a[i],h_i = i;
                if(l > a[i])
                    l = a[i];
            }
            if(h == l)break;
            steps += h-l;
            for(int i = 0; i < n; i++)a[i] += h-l;
            a[h_i] -= h-l;
        }
        return steps;
    }
};

//add 1 to all n-1 elements is the same as subtracting 1 at 1 element

class Solution {
public:
    int minMoves(vector<int>& a) {
        int ans = 0, n = a.size();
        int m = *min_element(a.begin(),a.end());
        for(int i = 0; i < n; i++)
            ans += a[i]-m;
        return ans;
    }
};