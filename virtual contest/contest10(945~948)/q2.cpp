class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size(),m = popped.size(),i = 1,j = 0;
        if(n != m )return false;
        if(!n)return true;
        s.push(pushed[0]);
        int counter = 1;
        while(i < n || j < m){
            int next = -1000000; 
            if(!s.empty())next = s.top(); //get top 
            if(next != popped[j]){ //keep pushing
                s.push(pushed[i]);
                ++i;
            }
            else{ //need poping
                s.pop();
                ++j;
            }
            ++counter;
            if(counter > m+n)return false;
        }
        return true;
    }
};