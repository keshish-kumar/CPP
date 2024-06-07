class Solution {
public:
    bool partition(vector<int>& nums, int sum, int n , vector<vector<int>>& dp){
        
        if(sum == 0) return true;
        
        if(n==0 ) return nums[n]==sum;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        int notpick = partition(nums,sum,n-1,dp);
        
        int pick = false;
        
        if(sum>=nums[n])
                pick = partition(nums,sum-nums[n],n-1,dp);
        
        return dp[n][sum] = notpick||pick;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
                sum += nums[i];
        
       
        
        if(sum%2 != 0) return false;
         sum = sum/2;
//         vector<vector<int>> dp(n,vector<int>(sum+1 ,-1));
        
//         return partition(nums,sum,n-1,dp);
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        
        for(int i=0;i<=n;i++)
            dp[i][0] = true;    // this indicates that when sum is 0 its always true
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                bool pick = dp[i-1][j];
                bool notpick = false;
                if(j>=nums[i-1]){
                    notpick = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = pick||notpick;
            }
        }
        
            
       return dp[n][sum];     
        
    }
};