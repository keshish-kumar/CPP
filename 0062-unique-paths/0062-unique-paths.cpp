class Solution {
public:
    int solve(int m, int n, int i, int j,vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=0;
        if(i+1<m )
         down =  solve(m,n,i+1,j,dp);
        int up=0;
        if(j+1 < n)
           up = solve(m,n,i,j+1,dp);
        
        return dp[i][j] = down+up;
        
    }
    
    int uniquePaths(int m, int n) {
        
        
        
        vector<int> dp(n+1,0);
      
        for(int i=0;i<m;i++){
             vector<int> temp(n+1,0);
            for(int j=0;j<n;j++){
                
              if(i==0 && j==0) temp[j]=1;
               else{ int down=0;
                 if((i-1) >= 0 )
                    down =  dp[j];
                int up=0;
                if((j-1) >= 0)
                    up = temp[j-1];
            temp[j] = up+down;}
               cout<<dp[j]<<" ";
            }
            dp = temp;
            cout<<endl;
        }
       
        return dp[n-1];
    }
};