//q146
typedef pair<int,int> ii;
class LRUCache {
public:
	//key : for every put/get, we move the required item to the front
	//need to do both operation in O(1)
	//=> can not use vector / array 
	//O(1) access of key => hash table
	//O(1) move to front => doubly linked list
    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end())return -1; //can not find
        lis.splice(lis.begin(),lis,it->second); //(pos,container,iterator)
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()){
        	it->second->second = value; //change value
        	//move it to the front
        	lis.splice(lis.begin(),lis,it->second);
        }
        else{
        	if(lis.size() == limit){
        		//erase the last elemet in list and map
        		auto& e = lis.back();
        		mp.erase(e.first);
        		lis.pop_back();
        	}
        	lis.emplace_front(key,value); //create & insert at the front of list
        	mp[key] = lis.begin();
        }
    }

private:
	int limit;
	list<ii> lis;
	unordered_map<int,list<ii> :: iterator> mp;
};

/*
LRUCache(2)
put(1,1)
put(2,2)
get(1) -> return 1
put(3,3) -> delete (2,2)
get(2) -> return -1
put(4,4) -> delete (1,1)
get(1) -> return -1
get(3) -> return 3
get(4) -> return 4
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */