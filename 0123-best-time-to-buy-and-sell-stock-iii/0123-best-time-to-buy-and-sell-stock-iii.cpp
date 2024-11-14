class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int count,vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(count==2) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy){
            return dp[i][buy][count] = max(-prices[i]+solve(prices,i+1,!buy,count,dp),solve(prices,i+1,buy,count,dp));
        }
        else{
            return dp[i][buy][count] = max(prices[i]+solve(prices, i+1, !buy,count+1,dp), solve(prices, i+1, buy,count,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1))); 
        return solve(prices,0,1, 0,dp);
    }
};