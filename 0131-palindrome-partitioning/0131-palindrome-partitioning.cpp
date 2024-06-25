class Solution {
public:
    bool ispanidrome(string s, int n, int i){
        
        while(i>n){
            if(s[i--]!=s[n++])
                    return false;
        
        }
        return true;
    }
    
    void solve(string s,int n, vector<string>& temp, vector<vector<string>>& ans){
        if(n>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=n;i<s.size();i++){
            if(ispanidrome(s,n,i)){
                temp.push_back(s.substr(n,i-n+1));
                solve(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        // Here we hvae to check for palindromic partitioning
        
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,temp,ans);
        return ans;
        
    }
};