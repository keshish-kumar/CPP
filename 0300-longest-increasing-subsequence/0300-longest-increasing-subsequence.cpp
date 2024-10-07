class Solution {
public:
    int solve(vector<int>& nums, int prev, int index){
        if(index==nums.size()){
            return 0;
        }
        // take
        int ans = INT_MIN;
        if(nums[index]>prev){
            ans = 1+solve(nums,nums[index],index+1);
        }
        ans = max(ans,solve(nums,prev,index+1));
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        // here we will assign previous eloement for comparision
        // int prev = INT_MIN;
        // return solve(nums,prev,0);
        
        // 2d dp
       vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        int ans =0;
        for(int i=0;i<nums.size();i++){
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};