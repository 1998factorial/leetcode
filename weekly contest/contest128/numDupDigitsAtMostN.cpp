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

//1 <= N <= 10^9
//ret =  the number of numbers that have no repeated digits that <= N
//use N - ret = desired result

int dp[1 << 10][10][2];

class Solution {
public:
    int len;
    vector<int> a;
    int solve(int mask, int pos, bool tight) {
        if (pos == len) return 1;
        int& ret = dp[mask][pos][tight];
        if (ret >= 0) return ret;
        ret = 0;
        int low = (pos == 0 ? 1 : 0);
        int high = ((a.size() == len && tight) ? a[pos] : 9);
        for (int i = low; i <= high; ++i) {
            if (mask & (1 << i)) continue;
            ret += solve(mask | (1 << i), pos + 1, a.size() == len && i == a[pos] && tight);
        }
        return ret;
    }
    int numDupDigitsAtMostN(int n) {
        a.clear();
        for (int m = n; m; m /= 10) a.push_back(m % 10);
        reverse(a.begin(), a.end());
        int ret = 0;
        for (len = 1; len <= a.size(); ++len) {
            memset(dp, 255, sizeof(dp));
            ret += solve(0, 0, true);
        }
        return n - ret;
    }
};


int main(){
    Solution s;
    cout << s.numDupDigitsAtMostN(100) << endl;
    cout << s.numDupDigitsAtMostN(1000) << endl;
    return 0;
}
