class Solution {
public:
    int solve(vector<int>& nums, int index, int prev){
        if(index>=nums.size()){
            return 0;
        }

        int l1 = INT_MIN;
        if( nums[index]>prev){
            l1 = 1+solve(nums,index+1,nums[index]);
        }
        int l2 = solve(nums,index+1,prev);

        return max(l1,l2);
    }
    int lengthOfLIS(vector<int>& nums) {
        // first we ill try with pick and not pick 

        //return solve(nums,0,INT_MIN);
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans =0;
        for(int i=0;i<nums.size();i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};