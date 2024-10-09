class Solution {
public:
    int solve(vector<int>& coins, int amount, int index,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(index>=coins.size() || amount<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];

        return dp[index][amount] = min(1+solve(coins,amount-coins[index],index,dp),solve(coins,amount,index+1,dp));

    }
    int coinChange(vector<int>& coins, int amount) {
        // this will return the sorted order in reverse
        // vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        // int ans = solve(coins,amount,0,dp);
        // if(ans==1e9) return -1;
        // else return ans;

        // Now we will look for space optimized approach

        vector<int> dp(amount+1,1e9);
        dp[0] = 0;
        for(int i=1;i<=coins.size();i++){
            vector<int> temp(amount+1,1e9);
            for(int j=0;j<=amount;j++){
                int left = 1e9;
                if(coins[i-1]<=j){
                    left = 1+temp[j-coins[i-1]];
                }
                int right = dp[j];

                temp[j] = min(left,right);

            }
            dp = temp;
        }
        return (dp[amount]==1e9)?-1:dp[amount];
    }
};