class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size()%2 != 0) return false;

        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            int r1 = (arr[i]%k+k)%k;
            int r2 = k-r1;
            if(r1==0) r2=0;
            if(mp.find(r2)!=mp.end()){
                mp[r2]--;
                if(mp[r2]==0) mp.erase(r2);
            }
            else{
                mp[r1]++;
            }
        }
        return mp.empty()?true:false;
    }
};