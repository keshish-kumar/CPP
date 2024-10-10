class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>>& dp){
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int t1 = 0;
        if((i+1)<obstacleGrid.size() && obstacleGrid[i+1][j]==0){
            t1 = solve(obstacleGrid,i+1,j,dp);
        }
        int t2 =0;
        if((j+1)<obstacleGrid[0].size() && obstacleGrid[i][j+1] == 0){
           t2 = solve(obstacleGrid,i,j+1,dp);
        }
        return dp[i][j] = t1+t2;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1) return 0;
        // vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        // return solve(obstacleGrid,0,0,ans,dp);
        
        int ans =0;
         vector<int> dp(obstacleGrid[0].size(),0);
         for(int i=0;i<obstacleGrid.size();i++){
            vector<int> temp(obstacleGrid[0].size(),0);
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0 && j==0) temp[j] = 1;
                else{
                 int t1 = 0;
                if((i-1)>=0){
                    t1 = dp[j];//solve(obstacleGrid,i+1,j,ans,dp);
                    }
                int t2 =0;
                if((j-1)>=0){
                 t2 = temp[j-1];//solve(obstacleGrid,i,j+1,ans,dp);
                }
               temp[j] = t1+t2;

                }
            if(obstacleGrid[i][j] == 1 ) temp[j] = 0;
            }

            dp=temp;
         }

         return dp[obstacleGrid[0].size()-1];
    }
};