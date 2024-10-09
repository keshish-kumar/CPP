class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum,int acc,vector<vector<int>>& dp){
        if(i>=nums.size()) return false;

        if(sum-acc == acc) return true;
        if(dp[i][acc]!=-1) return dp[i][acc];
        //pick
        return dp[i][acc] =  solve(nums,i+1,sum,acc+nums[i],dp) || solve(nums,i+1,sum,acc,dp);

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        //vector<vector< int >> dp(nums.size(),vector<int>(sum,-1));
        //return solve(nums,0,sum,0,dp);

        // we will use direclty sapce optimized approach
        if (sum % 2 != 0) return false;
        sum = sum/2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(int i=1;i<=nums.size();i++){
            vector<bool> temp(sum+1,false);
            temp[0] = true;
            for(int j=1;j<=sum;j++){
               // if(sum-j == j) return true;
                bool pick = dp[j];
                bool notpick = false;
                if(j>=nums[i-1])
                    notpick = dp[j-nums[i-1]];
                temp[j] = pick||notpick;
            }
            dp = temp;
        }

        return dp[sum];
    }
};