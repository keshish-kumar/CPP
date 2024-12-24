class Solution {
public:
    void solve(vector<int>& nums, int index, set<vector<int>>& ans){
        if(index==nums.size()){ans.insert(nums); return;}

        for(int i=index;i<nums.size();i++){
            
            swap(nums[i],nums[index]);
            solve(nums,index+1,ans);
            swap(nums[i],nums[index]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(nums,0,ans);
        vector<vector<int>> a;
        for(auto it: ans)
            a.push_back(it);
        return a;
    }
};