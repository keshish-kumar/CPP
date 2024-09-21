class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; // first will store the frequency and second will store the element
        for(auto it : mp){
            q.push({it.second,it.first});
            if(q.size()>k){
                q.pop();
            }
            // cout<<it.second<<" "<<it.first<<endl;
            
        }
        vector<int> ans;
        while(k--){
            // cout<<q.top().first<<" "<<q.top().second<<endl;
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;

    }
};