class Solution {
public:
    bool solve(string& s, set<string>& st, int index,vector<int>& dp ){

        if(index<0) return true;
        
        string temp = "";
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i>=0;i--){
            temp =s[i]+temp;
            if(st.find(temp)!=st.end() && solve(s,st,i-1,dp)) {
               return dp[index] = true;
            } 
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(s.size()+1,-1);
        for(int i=0;i<wordDict.size();i++)
            st.insert(wordDict[i]);
        return solve(s,st,s.size()-1,dp);
    }
};