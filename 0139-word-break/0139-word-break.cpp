class Solution {
public:
    bool solve(string & s,set<string>& st,int i ,vector<int>& dp){
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        for(int k=i;k<s.size();k++){
            if(st.find(s.substr(i,k-i+1))!=st.end() && solve(s,st,k+1,dp)){
                return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.size()+1,-1);
        for(int i = 0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return solve(s,st,0,dp);
    }
};