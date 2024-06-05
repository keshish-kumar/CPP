class Solution {
public:
    
    int path(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
        if(i==0 && j==0 ) return grid[i][j];
        
        int left = 1e9, right = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i>0) left =  path(grid,i-1,j,dp);
        if(j>0) right =  path(grid,i,j-1,dp);
        return  dp[i][j] = grid[i][j]  + min(left,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return path(grid,n-1,m-1,dp);
    }
};