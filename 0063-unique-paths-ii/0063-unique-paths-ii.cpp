class Solution {
public:
    
    int path(vector<vector<int>>& obstacleGrid , int i , int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return dp[i][j] = 1;
        if(obstacleGrid[i][j]==1) return dp[i][j] = 0;
        
        int left =0,right =0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i>0) left = path(obstacleGrid,i-1,j,dp);
        if(j>0) right = path(obstacleGrid,i,j-1,dp);
        return dp[i][j] = left + right;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        //  return path(obstacleGrid,n-1,m-1,dp);
       dp[0][0] = 1;
        
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){ 
                if(obstacleGrid[i][j] != 1){
                     if(i==0&&j==0)     //base case 
                         {
                            // if(obstacleGrid[0][0]==0)
                            // {
                            //     dp[i][j]=1;
                            //     continue;
                            // }
                        }   
                    
                    else{
                    int left = 0, right =0;
                    if(i>0 ) left = dp[i-1][j];
                     if(j>0 ) right = dp[i][j-1];
                     dp[i][j] = left + right;
                         }
                    }
                 }
             }
         return dp[n-1][m-1];
      
    }
};