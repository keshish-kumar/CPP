class Solution {
public:
    void solve(string &s,vector<string>& ans, int n1, int n2){
        if(n1==0 && n2==0){ans.push_back(s); return;}
        if(n1>0){
            s.push_back('(');
            solve(s,ans,n1-1,n2);
            s.pop_back();
        }
        if(n1<n2){
            s.push_back(')');
            solve(s,ans,n1,n2-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        solve(s,ans,n,n);
        return ans;
    }
};