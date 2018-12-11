//we use hash map to solve this problem
class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& pos) {
        map<pair<int,int> , int> it_map; // key = <left,right>, val = max(height)
        it_map[{0,100000000}] = 0; //ini horizon (given that pos[i][0] is at most 10^8)
        vector<int> heights;
        int max_height = 0;
        for(auto &v: pos){ //for all squares
            //erase intervals that are covered by the new square
            //append new intervals that are introduced by the new square
            vector<vector<int>> new_it;
            int side = v.second, l = v.first, r = v.first+v.second, h = 0;
            auto start = it_map.upper_bound({l,l}); 
            // get the first element in interval map that is after 
            // pair cmp: left < left || (left == left) => right < right
            if(start != it_map.begin() and (--start)->first.second <= l) ++start;
            //start is the first interval been touched by the new square
            while(start != it_map.end() and start->first.first < r){
                //for all intervals that are touched by the new square
                if(start->first.first < l)new_it.push_back({start->first.first,l,start->second});
                if(start->first.second > r)new_it.push_back({r,start->first.second,start->second});
                // ^ parts that are not covered by the square.
                //new_it: {left,right,height}
                h = max(h,start->second); //reset base height
                start = it_map.erase(start); //get rid of this old interval
            }
            it_map[{l,r}] = h + side; //new height of base [a,b]
            //add new intervals to map
            for(auto &t: new_it) it_map[{t[0],t[1]}] = t[2];
            //find max height
            max_height = max(max_height,h+side); //max_height is non increasing
            heights.push_back(max_height);
        }
        return heights;
    }
};