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
        //bool buy = false; 
        //vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
       // return solve(prices,0,buy,dp);
       vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));

        for(int i=prices.size()-1;i>=0;i--){

            dp[i][0] = max(-prices[i]+dp[i+1][1], dp[i+1][0]);

            dp[i][1] = max(prices[i]+dp[i+2][0],dp[i+1][1]);
        }

        return dp[0][0];
    }
};