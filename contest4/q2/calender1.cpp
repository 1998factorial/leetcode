class MyCalendar {
    vector<pair<int,int>> it;
public:
    
    bool book(int start, int end) {
        for(pair<int,int> p:it){
            if(p.first <= start){
                if(start < p.second)return false;
            }else{
                if(end > p.first)return false;
            }
            
        }it.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */