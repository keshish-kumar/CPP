class Solution {
public:
    
    void sub(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int i){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //. not pick any
        sub(nums,ans,temp,i+1);
        // pick that element
        temp.push_back(nums[i]);
        sub(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sub(nums,ans,temp,0);
        return ans;
    }
};