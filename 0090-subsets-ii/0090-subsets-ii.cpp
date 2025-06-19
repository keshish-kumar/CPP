class Solution {
public:
    void subset(vector<int>& nums, int n, set<vector<int>>& ans, vector<int> temp){
       ans.insert(temp);
        if(n>=nums.size()){
            
            return;
        }
        
        for(int i=n;i<nums.size();i++){
            if(i>n && nums[i]==nums[i-1]) continue;
            
            temp.push_back(nums[i]);
            subset(nums,i+1,ans,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subset(nums,0,st,temp);
        
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};