class Solution {
public:
    int stocks(vector<int>& prices,int i ,  int buy,vector<vector<int>>& dp,int fee){
        if(i>=prices.size()  ) return 0;
         if(dp[i][buy] != -1) return dp[i][buy];
        if(buy){
           return dp[i][buy] = max(-prices[i]-fee + stocks(prices,i+1,0 , dp,fee) , stocks(prices,i+1,1,dp,fee)) ;
            
        }
        else{
           return  dp[i][buy] =  max(prices[i]+stocks(prices,i+1,1,dp,fee) , stocks(prices, i+1,0,dp,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return stocks(prices,0,1,dp,fee);
    }
};