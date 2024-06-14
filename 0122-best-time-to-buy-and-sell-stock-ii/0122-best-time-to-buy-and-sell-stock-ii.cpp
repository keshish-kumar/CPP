class Solution {
public:
    int stocks(vector<int>& prices,int i ,  int buy , vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
           return dp[i][buy] =  max(-prices[i] + stocks(prices,i+1,0,dp) , stocks(prices,i+1,1,dp));
            
        }
        else{
           return  dp[i][buy] =  max(prices[i]+stocks(prices,i+1,1,dp) , stocks(prices, i+1,0,dp));
        }
        
        
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return stocks(prices,0,1,dp);
        
       // vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        // Now doiing it using space optimization
        
        vector<int> curr(2,0);
        vector<int> next(2,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit = 0;
                if(j){
                   profit = max(-prices[i] + next[0] , next[1]);
                }
                else{
                    profit = max(prices[i]+next[1] , next[0]);
                }
                curr[j] = profit;
            }
            next = curr;
        }
        return next[1];
    }
};