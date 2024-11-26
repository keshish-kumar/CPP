class Solution {
public:
    vector<string> ans;
    void solve(string & s, int close, int open,int n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<=n){
            s.push_back('(');
            solve(s,close,open+1,n);
            s.pop_back();
        }
        if(open>close){
            s.push_back(')');
            solve(s,close+1,open,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        solve(s,1,1,n); // 1->open 1->close
        return ans;
    }
};