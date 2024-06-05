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
        vector<vector<int>> dp(n,vector<int>(m,1e9));
       // return path(grid,n-1,m-1,dp);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)  dp[i][j] = grid[i][j];
                else{
                    int left = 1e9,right = 1e9;
                    if(i>0) left = dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(left,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};