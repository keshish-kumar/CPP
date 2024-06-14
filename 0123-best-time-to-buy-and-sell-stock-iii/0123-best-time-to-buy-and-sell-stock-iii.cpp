class Solution {
public:
     int stocks(vector<int>& prices,int i ,  int buy, int count,vector<vector<vector<int>>>& dp){
        if(i>=prices.size() || count == 0 ) return 0;
         if(dp[i][buy][count] != -1) return dp[i][buy][count];
        if(buy){
           return dp[i][buy][count] =  max(-prices[i] + stocks(prices,i+1,0 , count,dp) , stocks(prices,i+1,1,count,dp));
            
        }
        else{
           return  dp[i][buy][count] =  max(prices[i]+stocks(prices,i+1,1,count-1,dp) , stocks(prices, i+1,0,count,dp));
        }
        
        
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int count = 2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return stocks(prices,0,1,count,dp);
        
        
    }
};