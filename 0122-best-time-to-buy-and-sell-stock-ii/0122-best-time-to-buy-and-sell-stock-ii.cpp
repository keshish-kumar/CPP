class Solution {
public:
    int solve(vector<int>& prices, int buy, int index,vector<vector<int>>& dp){
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(!buy){
            return dp[index][buy] = max(-prices[index]+solve(prices,!buy,index+1,dp),solve(prices,buy,index+1,dp));
        }
        else{
            return dp[index][buy] = max(prices[index]+solve(prices,!buy,index+1,dp),solve(prices,buy,index+1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int buy = 0;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices, buy, 0,dp);
    }
};