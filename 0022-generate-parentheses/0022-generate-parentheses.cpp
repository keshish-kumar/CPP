class Solution {
public:
    void solve(int n, int open, int close,vector<string>& ans, string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<=n){
            s += '(';
            solve(n,open+1,close,ans,s);
            s.pop_back();
        }
        if(close<open){
            s += ')';
            solve(n,open,close+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open =1;
        int close = 1;
        vector<string> ans;
        string s;
        solve(n,open,close,ans,s);
        return ans;
    }
};