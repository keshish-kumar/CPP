class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // as we need to find most frequent element we will keep this i pair 
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        // Now elements wiht its frequency is stored.
        // top k frequent element
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back({pq.top().second});
            pq.pop();
        }

        return ans;
    }
};