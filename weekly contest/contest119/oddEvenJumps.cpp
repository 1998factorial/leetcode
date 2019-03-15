/*
    if odd jump: for all j > i && A[i] <= A[j] st A[j] is minimal 
    else: for all j > i && A[i] >= A[j] st A[j] is maximal 
    find number of valid points

    the key is to find where you can jump to given your index and state (odd/even)
*/
bool dp1[20000],dp2[20000];//odd,even
class Solution {
public:
    int n;
    int oddEvenJumps(vector<int>& A) {
        n = A.size();
        memset(dp1,false,sizeof(dp1));
        memset(dp2,false,sizeof(dp2));
        dp1[n-1] = true;
        dp2[n-1] = true;
        map<int,int> mp1; //ascending odd
        map<int,int,greater<int>> mp2; //descending even
        mp1[A[n-1]] = n-1;
        mp2[A[n-1]] = n-1;
        int cnt = 1;
        for(int i = n-2; i >= 0; i--){
            auto it1 = mp1.lower_bound(A[i]);//A[j] >= A[i] for odd
            auto it2 = mp2.lower_bound(A[i]);//A[j] <= A[i] for even
            if(it1 != mp1.end()){
                dp1[i] = dp2[it1->second],cnt += dp1[i];
            }
            if(it2 != mp2.end()){
                dp2[i] = dp1[it2->second];
            }
            mp1[A[i]] = mp2[A[i]] = i;
        }
        return cnt;        
    }
};
/*
    for map<int,int>, keys are sorted in ascending order and if call lower_bound(a), 
    it will return an iterator that points to an element that has key val not less than 
    a.
    for map<int,int,greater<int>>, keys are sorted in descending order and if call 
    lower_bound(a), it will return an iterator points to an element that has key val
    not greater than a.
*/

