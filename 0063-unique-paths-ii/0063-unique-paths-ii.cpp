class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j,int& ans,vector<vector<int>>& dp){
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1){
            ans++;
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int t1 = 0;
        if((i+1)<obstacleGrid.size() && obstacleGrid[i+1][j]==0){
            t1 = solve(obstacleGrid,i+1,j,ans,dp);
        }
        int t2 =0;
        if((j+1)<obstacleGrid[0].size() && obstacleGrid[i][j+1] == 0){
           t2 = solve(obstacleGrid,i,j+1,ans,dp);
        }
        return dp[i][j] = t1+t2;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int ans =0;
       vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return solve(obstacleGrid,0,0,ans,dp);
         return ans;
        // int ans =0;
        //  vector<int> dp(obstacleGrid[0].size(),0);
        //  for(int i=1;i<obstacleGrid.size();i++){
        //     vector<int> temp(obstacleGrid[0].size(),0);
        //     for(int j=1;j<obstacle.size();j++){

        //     }
        //  }
    }
};