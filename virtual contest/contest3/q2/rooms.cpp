//dfs approach
class Solution {
public:
    bool search(vector<vector<int>>& rooms, vector<bool>& seen, int pos){
        bool BeenAll = true;
        for(int i = 0; i < seen.size(); i++)
            if(!seen[i]){BeenAll = false;}
        
        if(BeenAll)return true;
        
        for(int j = 0; j < rooms[pos].size(); j++){
            if(!seen[rooms[pos][j]]){
                seen[rooms[pos][j]] = true;
                if(search(rooms,seen,rooms[pos][j]))return true;
            }
        }return false;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size(),false);
        seen[0] = true;
        return search(rooms,seen,0);
    }
};