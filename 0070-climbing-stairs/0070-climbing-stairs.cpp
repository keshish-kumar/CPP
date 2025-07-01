class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n] =  solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        if(n==1 || n==2) return n;
        int num1=1;
        int num2=2;

        for(int i=3;i<=n;i++){
            int temp = num1+num2;
            num1 = num2;
            num2 = temp;
        }

        return num2;
    }
};