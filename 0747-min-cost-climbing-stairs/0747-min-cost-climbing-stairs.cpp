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
        // int n = cost.size();
        // vector<int> dp(cost.size()+1,-1);
        // return min(solve(cost,0,dp),solve(cost,1,dp));

        
        int n = cost.size();
        if(n==2) return min(cost[n-1],cost[n-2]);

        int n1 = cost[0];
        int n2 = cost[1];
        for(int i=2;i<cost.size();i++){
            int temp = min(n1,n2);
            n1 = n2;
            n2 = cost[i]+temp;
        }
        return min(n1,n2);
    }
};