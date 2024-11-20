class Solution {
public:
    int solve(vector<int>& prices, int buy,int i,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0){
            return dp[i][buy] = max(-prices[i]+solve(prices,!buy,i+1,dp),solve(prices,buy,i+1,dp));
        }
        else{
            return dp[i][buy] = max(prices[i]+solve(prices,!buy,i+2,dp),solve(prices,buy,i+1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        // there is cool down periojd which need to be considered
        int buy=0;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,buy,0,dp);
    }
};