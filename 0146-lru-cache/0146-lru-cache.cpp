class LRUCache {
public:
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    list<int> dll; // stores the key 
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        // if key is already present in map/dll
        if(mp.find(key) != mp.end()){
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key] = {dll.begin(),mp[key].second};
            return mp[key].second;
        }

        return -1;

    }
    
    // always remebr recently added or used will be at the begining 
    // least recently used will be at the last
    void put(int key, int value) {
        // if key is already present in list;
        // fidn the address and than dlete that node form that address
        if(mp.find(key)!=mp.end()){
            dll.erase(mp[key].first);// delete that node
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(),value};
        }

        if(dll.size()>n){

            int k  = dll.back();
            dll.pop_back();
            mp.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */