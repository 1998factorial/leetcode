/*
    if odd jump: for all j > i && A[i] <= A[j] st A[j] is minimal 
    else: for all j > i && A[i] >= A[j] st A[j] is maximal 
    find number of valid points

    the key is to find where you can jump to given your index and state (odd/even)
*/
class Solution {
public:
    int oddEvenJumps(vector<int>& a) {
        int ans = 1, n = a.size();
        if(!n)return 0;
        vector<bool> odd(n),even(n);
        odd[n-1] = even[n-1] = true;
        map<int,int,greater<int>> h; 
        map<int,int,less<int>> l;
        h[a[n-1]] = l[a[n-1]] = n-1;
        for(int i = n-2; i >= 0; i--){
            //for even: find maximal a[j] st a[j] <= a[i]
            //for odd: find minimal a[j] st a[j] >= a[i]
            auto x = l.lower_bound(a[i]);//minimal element thats greater than a[i]
            auto y = h.lower_bound(a[i]);//maximal element thats smaller than a[i]
            if(x != l.end())odd[i] = even[x->second];//,printf("min of greater: %d\n",x->first);
            if(y != h.end())even[i] = odd[y->second];//,printf("max of smaller: %d\n",y->first);
            h[a[i]] = l[a[i]] = i;
            ans += odd[i];
        }
        return ans;
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

