class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    int n;
    LRUCache(int capacity) {
         n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key] = {dll.begin(),mp[key].second};
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key] = {dll.begin(),mp[key].second};
            return;
        }
        if(dll.size()>=n){mp.erase(dll.back()); dll.pop_back();}
        dll.push_front(key);
        mp[key]={dll.begin(),value};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */