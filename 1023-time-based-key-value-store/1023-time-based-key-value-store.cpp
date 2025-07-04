class TimeMap {
public:
    map<string,priority_queue<pair<int,string>>> mp;
    TimeMap() {
        
    }
   
    void set(string key, string value, int timestamp) {
        mp[key].push({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
            vector<pair<int,string>> temp;
            while(!mp[key].empty() && mp[key].top().first > timestamp){
                temp.push_back(mp[key].top());
                mp[key].pop();
            }
            string ans="";
            if(!mp[key].empty()) ans = mp[key].top().second;
            for(int i=0;i<temp.size();i++){
                mp[key].push(temp[i]);
            }
            return ans;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */