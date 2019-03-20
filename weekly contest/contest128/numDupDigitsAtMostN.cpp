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
/*
class Solution {

    private int getTotal(int length) {
        int ans = 1;
        for (int i = 1;i <= length;i ++) {
            if (i == 1) {
                ans *= 9;
            } else {
                ans *= (10 - i + 1);                
            }
        }
        return ans;
    }
    
    private static int[][][] dp = new int[20][2000][2]; 
    
    public int numDupDigitsAtMostN(int N) {
        int i , j , k;
        for (i = 0;i < 20;i ++) {
            for (j = 0;j < 2000;j ++) {
                for (k = 0;k < 2;k ++) {                    
                    dp[i][j][k] = - 1;                  
                }
            }
        }       
        String string = Integer.toString(N);
        int ans = 0;
        for (i = 1;i < string.length();i ++) {
            ans += getTotal(i);
        }
        ans += dfs(string , 0 , 0 , 0);
        return N - ans;     
    }
    
    private int dfs(String s , int current , int bitmap , int less) {    
        if (current == s.length()) {
            return 1;
        } else {
            if (dp[current][bitmap][less] >= 0) {
                return dp[current][bitmap][less];
            } else {
                int ans = 0;
                if (less > 0) {
                    for (int i = 0;i < 10;i ++) {
                        if ((bitmap & (1 << i)) == 0) {
                            ans += dfs(s , current + 1 , bitmap | (1 << i) , less);                         
                        }
                    }                   
                } else {
                    int value = s.charAt(current) - '0' , start = 0;                    
                    if (current == 0) {
                        start = 1;                      
                    }
                    for (int i = start;i <= value;i ++) {
                        if ((bitmap & (1 << i)) == 0) {
                            if (i < value) {                                
                                ans += dfs(s , current + 1 , bitmap | (1 << i) , 1);
                            } else if (i == value) {                                
                                ans += dfs(s , current + 1 , bitmap | (1 << i) , 0);                                
                            }                       
                        }
                    }
                }    
                return dp[current][bitmap][less] = ans;
            }           
        }       
    }
}
*/
