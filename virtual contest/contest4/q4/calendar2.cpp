class MyCalendarTwo {
    vector<pair<int,int>> its;
public:
    bool book(int head, int tail) {
        //false if triple overlap
    	vector<pair<int,int>> lp;

    	for(pair<int,int> p: its){
    		if(max(head,p.first) < min(tail,p.second)){
    			//input overlap 
    			pair<int,int> it = {max(head,p.first),min(tail,p.second)};
    			for(pair<int,int> l:lp){
    				if(max(it.first,l.first) < min(it.second,l.second))
    					return false; // overlaps with overlapped intervals
    			}
    			lp.push_back(it);
    		}
    	}
    	its.push_back({head,tail});
    	return true;
    }
};

//keep observation: if 2 interval intersect
//then max(left1,left2) < min(right1,right2)

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */