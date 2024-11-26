class Solution {
public:
     int solve(vector<int>& prices, int buy, int index,vector<vector<vector<int>>>& dp,int k){
        if(index>=prices.size()) return 0;
        if(k==2) return 0;
        if(dp[index][buy][k]!=-1) return dp[index][buy][k];
        if(!buy){
            return dp[index][buy][k] = max(-prices[index]+solve(prices,!buy,index+1,dp,k),solve(prices,buy,index+1,dp,k));
        }
        else{
            return dp[index][buy][k] = max(prices[index]+solve(prices,!buy,index+1,dp,k+1),solve(prices,buy,index+1,dp,k));
        }
    }
    int maxProfit(vector<int>& prices) {
         int buy = 0;
         
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices, buy, 0,dp,0);
    }
};