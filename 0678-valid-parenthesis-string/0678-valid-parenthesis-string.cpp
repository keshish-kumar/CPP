class Solution {
public:
    bool solve(string& s, int i, int count,vector<vector<int>>& dp){
        if(count<0) return false;
        if(i==s.size()){
            return count ==0;
        }
        if(dp[i][count] != -1) return dp[i][count];
        if(s[i] == '(') return dp[i][count] = solve(s,i+1,count+1,dp);
        else if(s[i] == ')') return dp[i][count] =solve(s,i+1,count-1,dp);
        else{
            return dp[i][count] =solve(s,i+1,count+1,dp)||solve(s,i+1,count-1,dp)||solve(s,i+1,count,dp);
        }
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(s,0,0,dp);


    }
};