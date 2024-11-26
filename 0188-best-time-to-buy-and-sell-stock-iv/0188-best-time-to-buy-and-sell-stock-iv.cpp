class Solution {
public:
    int solve(vector<int>& prices, int buy, int index,vector<vector<vector<int>>>& dp,int k, int & count){
        if(index>=prices.size()) return 0;
        if(k==count) return 0;
        if(dp[index][buy][k]!=-1) return dp[index][buy][k];
        if(!buy){
            return dp[index][buy][k] = max(-prices[index]+solve(prices,!buy,index+1,dp,k,count),solve(prices,buy,index+1,dp,k,count));
        }
        else{
            return dp[index][buy][k] = max(prices[index]+solve(prices,!buy,index+1,dp,k+1,count),solve(prices,buy,index+1,dp,k,count));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
         int buy = 0;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(prices, buy, 0,dp,0,k);
    }
};