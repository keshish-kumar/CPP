class Solution {
public:
    int solve(vector<int>& prices, int i, int buy,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(-prices[i]+solve(prices,i+1,!buy,dp),solve(prices,i+1,buy,dp));
        }
        else{
            return dp[i][buy] = max(prices[i]+solve(prices,i+1,!buy,dp),solve(prices,i+1,buy,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        // if w bought than we cannot buy firuther we have to sell 
        // simillalry if we solbde we hvae to buy first
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};