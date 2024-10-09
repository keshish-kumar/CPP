class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,vector<vector<int>>& dp){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
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
        //vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        //return solve(grid,0,0,dp);

        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int left = 1e9,right=1e9;
                    if(i>0) left = dp[i-1][j];
                    if(j>0) right = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(left,right);
                }
            }
        }

        return dp[grid.size()-1][grid[0].size()-1];

    }
};