class Solution {
public:
    int solve(vector<int>& nums, int index){
        if(index>=nums.size()) return 0;
        int ans = -1e9;
        for(int i=index;i<nums.size();i++){
            // tke that element
            int temp =  max(nums[i]+solve(nums,i+2),solve(nums,i+1));
            ans = max(ans,temp);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        //return solve(nums,0);
        vector<int> dp(nums.size()+1,0);
        dp[1] = nums[0];
            for(int i=2;i<=nums.size();i++){
            // tke that element
                int temp =  0;
                int temp1 = 0;
                if((i-2)>=0){
                    temp1 = nums[i-1]+dp[i-2];
                }
                if((i-1)>=0) temp = dp[i-1];
                dp[i] = max(temp1,temp);
            }
        return dp[nums.size()];
    }
};