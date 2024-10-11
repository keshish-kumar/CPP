class Solution {
public:
    bool solve(string & s, set<string>& st, int i){
        if(i>=s.size()) return true;
        for(int k=i;k<s.size();k++){
            if(st.find(s.substr(i,k-i+1))!=st.end() && solve(s,st,k+1)){
                return true;
            }

        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string it:wordDict){
            st.insert(it);
        }
        return solve(s,st,0);
    }
};