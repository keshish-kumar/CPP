class Solution {
public:
    bool permut(int start, int end, string s){
        if(end==start) return true;
        while(start<end){
            if(s[start++]!=s[end--]) return false;

        }
        return true;
    }
    void solve(string& s ,int n,vector<vector<string>>& ans, vector<string>& temp){
        if(n>=s.size()){
            ans.push_back(temp);
        }
        for(int i=n;i<s.size();i++){
            if(permut(n,i,s)){
                temp.push_back(s.substr(n,(i-n+1)));
                // cout<<temp<<endl;
                solve(s,i+1,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // first we have to make one division than we have to make another division
        vector<vector<string>> ans;
        vector<string> temp;
        solve( s, 0,ans,temp);
        return ans;
        
    }
};