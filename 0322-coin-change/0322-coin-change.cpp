class Solution {
public:
    int solve(vector<int>& coins, int amount,int index,vector<vector<int>>& dp){
        if(amount==0){  return 0;}
        if(index == coins.size()){
            return INT_MAX;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        // pick coins
        int take=INT_MAX;
        if((amount)>=coins[index]){
            
            int temptake = solve(coins,amount-coins[index],index,dp);
            if(temptake!=INT_MAX) take = temptake+1;
    
        }
        // not pick
        int nottake = solve(coins,amount,index+1,dp);

        return dp[index][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        // here we have infinit supply of coins.
        int ans = INT_MAX;
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        ans =  solve(coins,amount,0,dp);
      
        if(ans==INT_MAX) return -1; else return ans;
        
    }
};