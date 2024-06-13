class Solution {
public:
    int count(string text1, int n , string text2 , int m, vector<vector<int>>& dp){
        if(m==0 || n==0) return 0;
        if(text1[n-1] == text2[m-1]) return 1+count(text1,n-1,text2,m-1,dp);
        
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m] = max(count(text1,n-1,text2,m,dp),count(text1,n,text2,m-1,dp));
    }
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();
        string s2 ="";
        for(int i=n-1;i>=0;i--)
                s2 += s1[i];
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       // return count(s1,n,s2,n,dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};