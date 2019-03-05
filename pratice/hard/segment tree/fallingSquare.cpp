//q699
//skyline problem


typedef pair<int,int> ii;

struct interval{
    int left;
    int right;
    int height;
};

class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& pos) {
        vector<int> ans;
        map<ii,int> mp;
        mp[{0,100000000}] = 0;
        int max_height = 0;
        for(auto& p : pos){
            int l = p.first, side = p.second, r = l+side;
            //get first interval in mp that touches p
            auto start = mp.upper_bound({l,l});//first interval that intersect with p
            if(start != mp.begin() && (--start)->first.second <= l)++start;
            vector<interval> nxt;
            int h = 0;
            while(start != mp.end() && start->first.first < r){
                if(start->first.first < l)nxt.push_back({start->first.first,l,start->second});
                if(start->first.second > r)nxt.push_back({r,start->first.second,start->second});
                h = max(h,start->second);
                cout << h << endl;
                start = mp.erase(start);
            }
            mp[{l,r}] = h+side;
            max_height = max(max_height,h+side);
            ans.push_back(max_height);
            for(interval it : nxt){
                mp[{it.left,it.right}] = it.height;
            }
        }
        return ans;
    }
};

