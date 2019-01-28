class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size(), ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int a = A[i] & A[j];
                for(int k = j; k < n; k++){
                    int b = a & A[k];
                    if(!b){    
                        if(i == j && j == k)ans += 1; //1 choice
                        else if(i == j || i == k || j == k)ans += 3; //3C1 choices
                        else ans += 6; //3! choices
                    }
                }
            }
        }
        return ans;
    }
};