class Solution {
public:
    int solve(vector<int>& cost, int n,vector<int>& dp){
        if(n == cost.size()) return 0;
        if(n>=cost.size()) return 1e9; 
        if(dp[n]!=-1) return dp[n];
        dp[n] =  min(solve(cost,n+1,dp)+cost[n],solve(cost,n+2,dp)+cost[n]);
        return dp[n];
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size()+1,-1);
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};