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


int dp[1 << 10][10][2];
int cnt[10];
class Solution {
public:
	vector<int> A;
	int len;

	int solve(int state, int pos, int less){
		if(pos >= len)return 1;
		if(dp[state][pos][less] >= 0)return dp[state][pos][less];
		int ret = 0;
		if(less > 0){
			for(int i = 0; i < 10; i++){
				if(state & (1 << i))continue;
				ret += solve(state | (1 << i) , pos + 1, less);
			}
		}
		else{
			int Ai = A[pos];
			int i = (pos == 0) ? 1 : 0;
			for(; i < 10; i++){
				if(state & (1 << i))continue;
				if(i < Ai){
					ret += solve(state | (1 << i), pos + 1, 1);
				}
				else if(i == Ai){
					ret += solve(state | (1 << i), pos + 1, 0);
				}
			}
		}
		return dp[state][pos][less] = ret;
	}


	int numDupDigitsAtMostN(int n) {
		int N = n;
		while(N)A.push_back(N % 10), N /= 10;
		reverse(A.begin(),A.end());
		len = A.size();
		memset(cnt,0,sizeof(cnt));
		memset(dp,-1,sizeof(dp));
		int ret = 0;
		cnt[1] = 9;
		for(int i = 2; i < len; i++){
			cnt[i] = cnt[i-1]*(10 - i + 1);
		}
		for(int i = 1; i < len; i++)ret += cnt[i];
		ret += solve(0,0,0);
		return n-ret;
	}
};