class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<int> dp(m,0);
        dp[0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i] = dp[i-1]+grid[0][i];
        }

        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(j==0){temp[j] = grid[i][j]+dp[j];}
                else{
                    temp[j] = min(dp[j],temp[j-1])+grid[i][j];
                }
            }
            dp = temp;
        }
        return dp[m-1];
    }
};