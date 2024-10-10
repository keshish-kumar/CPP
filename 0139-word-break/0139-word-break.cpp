class Solution {
public:
    bool solve(string & s, set<string>& st, int i,vector<int>& dp){
         if(i>=s.size()) return true;
        if(dp[i]!=-1) return dp[i];
         for(int k=i;k<s.size();k++){
            if(st.find(s.substr(i,k-i+1))!=st.end() && solve(s,st,k+1,dp)){
                return dp[i] = true;
            }
         }
         return dp[i] =  false;


    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<int> dp(s.size(),-1);
        return solve(s,st,0,dp);
    }
};