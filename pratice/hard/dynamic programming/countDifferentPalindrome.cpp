/*
Input: 
S = 'bccb'
Output: 6
Explanation: 
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

Input: 
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361
Explanation: 
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7.
*/

int dp[1024][1024][4];
class Solution {
public:

    int countPalindromicSubsequences(string s) {
    	vector<vector<int>> dp;
    	vector<int> v(s.size(),0);
    	for(int i = 0; i < S.size(); i++)
    		dp.push_back(v);
    	for(int i = 0; i <)

    }
};





