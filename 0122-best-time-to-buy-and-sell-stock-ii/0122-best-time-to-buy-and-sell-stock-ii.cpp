class Solution {
public:
    int stocks(vector<int>& prices,int i ,  int buy){
        if(i>=prices.size()) return 0;
        if(buy){
           return  max(-prices[i] + stocks(prices,i+1,0) , stocks(prices,i+1,1));
            
        }
        else{
           return   max(prices[i]+stocks(prices,i+1,1) , stocks(prices, i+1,0));
        }
        
        
    }
    int maxProfit(vector<int>& prices) {
        
       // return stocks(prices,0,1);
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit = 0;
                if(j){
                   profit = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else{
                    profit = max(prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};