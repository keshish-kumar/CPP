class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return ;
        }

        // pick 
        temp.push_back(nums[index]);
        solve(nums,ans,temp,index+1);
        temp.pop_back();
        // not pick
        solve(nums,ans,temp,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,ans,temp,0);
        return ans;
    }
};