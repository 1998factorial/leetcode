#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
using namespace std;


class Solution {
public:
    int n,end,start;
    string a,b;
    map<int,map<string,int> > dp;
    
    int solve(int state){
        if(state == end)return 0;
        if(dp[state][a])return dp[state][a];
        int ret = 1 << 29;
        for(int i = 0; i < n; i++){
            if(state & (1 << i))continue;
            int j = 0;
            while(j < n){
                if(j != i && !(state & (1 << j)) && a[j] == b[i])break;
                j++;
            }
            if(a[i] == b[j]){
                swap(a[i],a[j]);
                ret = min(ret,1 + solve(state | (1 << i) | (1 << j)));
            }
            else {
                swap(a[i],a[j]);
                ret = min(ret,1 + solve(state | (1 << i)));
            }
            swap(a[i],a[j]);
        }
        dp[state][a] = ret;
        return ret;
    }
    
    int kSimilarity(string A, string B) {
        n = A.size();
        end = (1 << n) - 1;
        a = A, b = B;
        start = 0;
        dp.clear();
        for(int i = 0; i < n; i++){
            if(A[i] == B[i])
                start |= (1 << i);
        }
        int ret = solve(start);
        return ret;
    }
};




int main(){
    Solution s;
    //Too bad, this solution is TLE
    //cout << s.kSimilarity("cdebcdeadedaaaebfbcf","baaddacfedebefdabecc") << endl;
    return 0;
}

