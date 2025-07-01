class Solution {
public:
    int solve(string& s, int i,vector<int>& dp){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int left = 0;
        if(s[i]!='0'){
            left = solve(s,i+1,dp);
        }
        int right = 0;
        if(i + 1 < s.size() && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))){
            right = solve(s,i+2,dp);
        }

        return dp[i] =  right+left;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return solve(s,0,dp);
    }
};