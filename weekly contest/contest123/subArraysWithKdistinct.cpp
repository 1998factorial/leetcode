//1 <= n <= 20000
//1 <= K <= 20000
//1 <= A[i] <= n
//BRUTE FORCE
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(), ans = 0;
        for(int i = 0; i < n; i++){
        	set<int> s;
        	for(int j = i; j < n; j++){
        		s.insert(A[j]);
        		ans += (s.size() == K);
        	}
        }
        return ans;
    }
};
//O(n) sliding window approach (Other user's approach)
class Solution {
public:

	int atMostK(vector<int>& a, int k, int n){
		map<int,int> mp;
		int i = 0, ret = 0;
		for(int j = 0; j < n; j++){
			if(!mp[a[j]]++)k--;
			while(k < 0){
				if(!--mp[a[i]])k++;
				i++;
			}
			ret += j-i+1;
		}
		return ret;
	}

    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        return atMostK(A,K,n) - atMostK(A,K-1,n);
        //compute number of subarrays that have no more than K distinct
        //elements, subtract number of those have at most K-1 distincts
    }
};

//another sliding window approach(my solution)
//for j, there exist i_min and i_max => A[i_max...j] has K distincts
//and A[i_min...j] has K-1 distincts
//ans += i_min - i_max
//notice that this process is non-decreasing
//thus O(n)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size(),ans = 0,cnt_max = 0,cnt_min = 0,j = 0,i_min = 0,i_max = 0;
        map<int,int> m_max, m_min;
        for(;j < n && cnt_max < K; j++){
            if(!m_max[A[j]]++)cnt_max++,cnt_min++;
            m_min[A[j]]++;
        }
        if(cnt_max < K)return ans;
        //i_max...i_min...j...
        while(cnt_min >= K){
            if(!--m_min[A[i_min]])cnt_min--;
            i_min++;
        }
        ans += i_min - i_max;
        for(; j < n; j++){
            if(!m_max[A[j]]++)cnt_max++;
            if(!m_min[A[j]]++)cnt_min++;
            while(cnt_max > K){
                if(!--m_max[A[i_max]])cnt_max--;
                i_max++;
            }
            while(cnt_min >= K){
                if(!--m_min[A[i_min]])cnt_min--;
                i_min++;
            }
            ans += i_min - i_max;
        }
        return ans;
    }
};
