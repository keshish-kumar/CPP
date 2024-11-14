class Solution {
public:

    int solve(vector<int>& prices, int i, int buy, int count,int k, vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(count==k) return 0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy){
            return dp[i][buy][count] = max(-prices[i]+solve(prices,i+1,!buy,count,k,dp),solve(prices,i+1,buy,count,k,dp));
        }
        else{
            return dp[i][buy][count] =max(prices[i]+solve(prices,i+1,!buy,count+1,k,dp),solve(prices,i+1,buy,count,k,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,0,k,dp);
    }
};