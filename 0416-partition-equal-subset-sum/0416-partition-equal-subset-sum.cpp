class Solution {
public:
    bool solve(vector<int>& nums, int target, int i,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(target<0 || i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        dp[i][target] = solve(nums,target-nums[i],i+1,dp) || solve(nums,target,i+1,dp);
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        //. equal partititon can onky be performed when sum is even number odd number cannot be partriitoned equally
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;

        int target = sum/2;
       // vector<vector<int> > dp(nums.size(),vector<int>(target+1,-1));
       // return solve(nums,target,0,dp);
        
        // lets try using tabulation approach
        // if there are no elemlents than always false for particluao target
        // if target == 0 than always true
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(int i=1;i<=nums.size();i++){
            vector<bool> temp(target+1,false);
            temp[0]=true;
            for(int j=1;j<=target;j++){

                    bool pick = dp[j];
                    bool notpick = false;
                    if(nums[i-1]<=j){
                        notpick = dp[j-nums[i-1]];
                    }
                    temp[j] = pick||notpick;
                
            }
            dp = temp;
        }
        return dp[target];
    }
};