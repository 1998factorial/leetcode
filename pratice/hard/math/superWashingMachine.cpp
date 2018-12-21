/*
You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
3rd move:    2     1 <-- 3    =>    2     2     2   
Example2

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
*/
//此题需要将一排洗衣机看成整体
//突破口：
//若n整除sum则存在一组解，则只需要找出解集中的最小解。
//从n个洗衣机中选出一个洗衣机 M[i], 考虑它左手边以及右手边洗衣机内衣物总和。
//若左边与右边同时低于期望值，那么很显然，M[i]中的衣物數量很大，由於每一次都只能
//傳送一件衣服，故將左右兩邊同時加和
//否則，兩邊可以同時傳送衣物，故選用MAX
class Solution {
public:
    int findMinMoves(vector<int>& M) {
        //if n|sum then there exists one solution
        //the key is to find how many steps it takes for the 
        //consider how many necessary steps needed for each machine
        int n = M.size();
        if(!n)
            return 0;
        vector<int> sum(n,0);
        int ans = 0;
        sum[0] = M[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + M[i];
        }
        if(sum[n-1] % n != 0)
            return -1;
        int target = sum[n-1]/n;
        for(int i = 0; i < n; i++){
            //[0]....[i]....[n-1]
            int steps = 0;
            if(i == 0 or i == n-1)
                steps = abs(target*(n-1) - sum[n-1] + M[i]);
            else{
                int L = target * i - sum[i-1];
                int R = target * (n-i-1) - sum[n-1] + sum[i];
                if(L >= 0 and R >= 0) //both sides lack clothes, can only transfer by M[i]
                    steps = L+R;
                else if(L < 0 and R < 0) //both sides have too many clothes, can transfer from both side
                    steps = max(abs(L),abs(R));
                else //one side has too many, one side has too little, can transfer at the same time
                    steps = max(abs(L),abs(R));
            }
            ans = max(ans,steps);
        }
        return ans;
    }

};










