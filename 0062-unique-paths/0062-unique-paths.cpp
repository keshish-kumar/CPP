class Solution {
public:
    int solve(int m, int n, int i, int j,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int l = 0;
        if(i+1 < m && j < n){
           l +=  solve(m,n,i+1,j,dp);
        }
        if(i<m && j+1 < n){
            l += solve(m,n,i,j+1,dp);
        }
        return dp[i][j] = l;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);
    }
};