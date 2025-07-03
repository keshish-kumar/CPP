class Solution {
public:
    bool solve(string & s1, string & s2, string & s3, int i, int j, int t,vector<vector<vector<int>>>& dp){
        if(t>=s3.size()) return true;
        if(dp[i][j][t] != -1) return dp[i][j][t];
        if(s1[i] == s3[t] && s2[j] == s3[t]){
            return dp[i][j][t] = solve(s1,s2,s3,i+1,j,t+1,dp)||solve(s1,s2,s3,i,j+1,t+1,dp);
        } 
        else if(s1[i] == s3[t]){
            return dp[i][j][t] = solve(s1,s2,s3,i+1,j,t+1,dp);
        }
        else if(s2[j] == s3[t]){
            return dp[i][j][t] = solve(s1,s2,s3,i,j+1,t+1,dp);
        }
        else{
            return dp[i][j][t] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if((n1+n2)!=n3) return false;
        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};