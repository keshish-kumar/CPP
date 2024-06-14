class Solution {
public:
    int stocks(vector<int>& prices,int i ,  int buy,vector<vector<int>>& dp){
        if(i>=prices.size()  ) return 0;
         if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
           return dp[i][buy] =  max(-prices[i] + stocks(prices,i+1,0 , dp) , stocks(prices,i+1,1,dp));
            
        }
        else{
           return  dp[i][buy] =  max(prices[i]+stocks(prices,i+2,1,dp) , stocks(prices, i+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int count = 2;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return stocks(prices,0,1,dp);
    }
};