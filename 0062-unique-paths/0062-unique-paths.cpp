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
        //vector<vector<int>> dp(m,vector<int>(n,-1));
       // return solve(0,0,m-1,n-1,ans,dp);
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n+1,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[j]=1;
                else{
                int up=0;
                if(i-1 >=0){
                   up = dp[j];
                 }
                 int down=0;
                 if(j-1 >=0){
                    down = temp[j-1];
                 }
                 temp[j] = up+down;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};