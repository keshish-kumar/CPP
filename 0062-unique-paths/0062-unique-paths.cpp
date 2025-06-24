class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int l = 0;
        if((i+1)<m) l = solve(m,n,i+1,j,dp);
        int r = 0;
        if(j+1<n) r = solve(m,n,i,j+1,dp);

        dp[i][j] = l+r;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,0,0,dp);
        
    }
};