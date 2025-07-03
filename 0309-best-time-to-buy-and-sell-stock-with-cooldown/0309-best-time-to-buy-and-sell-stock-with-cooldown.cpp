class Solution {
public:
    int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(!buy){
            return dp[i][buy] = max(-prices[i]+solve(prices,i+1,!buy,dp) , solve(prices,i+1,buy,dp));
        }
        else{
            return dp[i][buy] = max(prices[i]+ solve(prices,i+2,!buy,dp),solve(prices,i+1,buy,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        bool buy = false; 
        int val = 0;
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,buy,dp);
    }
};