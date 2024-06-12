class Solution {
public:
    int coin(vector<int>& coins, int amount, int n,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(n<0) return 1e9;
        if(dp[n][amount]!=-1) return dp[n][amount];
        int notpick = 0+coin(coins,amount,n-1,dp);
        int pick = 1e9;
        if(amount>=coins[n]){
           int cpick = coin(coins,amount-coins[n],n,dp);
            if(cpick != 1e9)
                pick = cpick+1;
            
        }
        
        return dp[n][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        // vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        // int ans = coin(coins,amount,coins.size()-1,dp);
        // if(ans==1e9) return -1;
        // else return ans;
        
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,1e9));
        
        for(int i=0;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(i==0) dp[i][j] = INT_MAX;
                else if(j==0) dp[i][j] = 0;
                else{
                    int notpick = dp[i-1][j];
                    int pick = INT_MAX;
                    if(coins[i-1]<=j){
                        int cpick = dp[i][j-coins[i-1]];
                        if(cpick != INT_MAX)
                            pick = 1+cpick;
                    }
                    dp[i][j] = min(pick,notpick);
                }
            }
        }
        if(dp[coins.size()][amount]==INT_MAX) return -1;
        else return dp[coins.size()][amount];
    }
};