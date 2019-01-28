class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp[key] == mp.end())return "";
        map<int,string>& m = mp[key];
        auto it = m.upper_bound(timestamp);
        if(it != m.begin()){
        	--it;
        	return it->second;
        }return "";
    }
private:
	map<string,<int,string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */