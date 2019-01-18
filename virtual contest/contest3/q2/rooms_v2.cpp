//bfs approach using queue
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> seen(rooms.size(),false);
        seen[0] = true;
        queue<int> Q;
        Q.push(0); // start with room[0]
        while(!Q.empty()){
            int n = Q.front(); //get next element
            Q.pop(); //remove next element
            for(auto &m : rooms[n]){
                if(!seen[m]){
                    seen[m] = true; // seen m
                    Q.push(m); // add m to queue
                }
            }
        }
        int num = 0;
        for(int i = 0; i < seen.size(); i++)
            num += seen[i]; // true = 1, false = 0, we can do sum here directly.
        return (num == seen.size());
    }
};