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
        // int ans = INT_MAX;
         vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,INT_MAX));
        // ans =  solve(coins,amount,0,dp);
      
        // if(ans==INT_MAX) return -1; else return ans;

        // Now we will do tabulation approach
        for(int i=0;i<=coins.size();i++){ // i I will consider it as index of coins
            for(int j=0;j<=amount;j++){   // j I will consider it as amount
                if(i==0 && j==0){dp[i][j]=0;}
                else if(i==0) {dp[i][j]=INT_MAX;}
                else if(j==0){dp[i][j]=0;}
                else{
                     int take=INT_MAX;
                    if((coins[i-1]) <= j ){
                            int temptake =  dp[i][j-coins[i-1]];
                            if(temptake!=INT_MAX) take = temptake+1;
    
                        }
                        // not pick
                    int nottake =  dp[i-1][j];
                    dp[i][j] = min(take,nottake);
                }
            }
        }
     if(dp[coins.size()][amount]==INT_MAX) return -1;
     else return dp[coins.size()][amount];
    }
};