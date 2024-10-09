class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        // right side
        int right = INT_MAX;
        if((j+1)<grid[0].size()){
            right = grid[i][j] + solve(grid,i,j+1,dp);
        }

        // down side
        int down = INT_MAX;
        if((i+1)<grid.size()){
            down = grid[i][j] + solve(grid,i+1,j,dp);
        }
        return dp[i][j] = min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // we will use recursion 
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(grid,0,0,dp);
    }
};