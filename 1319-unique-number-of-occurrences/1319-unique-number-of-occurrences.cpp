class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        // Now we need to check if same number exist or not
        set<int> ans; 
        for(auto it:mp){
            ans.insert(it.second);
        }

        return ans.size()==mp.size()?1:0;
    }
};