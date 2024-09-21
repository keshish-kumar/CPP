class Solution {
public:
    int solve(int i, int j, int m , int n, int & ans,vector<vector<int>>& dp){
        if(i==m && j==n){
            
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0;
        if(i<m){
            up = solve(i+1,j,m,n,ans,dp);
        }
        int down=0;
        if(j<n){
            down = solve(i,j+1,m,n,ans,dp);
        }
        return dp[i][j] = up+down;
        
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m-1,n-1,ans,dp);
        
    }
};