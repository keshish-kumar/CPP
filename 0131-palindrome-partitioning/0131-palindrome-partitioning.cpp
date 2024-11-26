class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool ispossible(string & s, int i, int j){
        
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    void solve(string & s, int i){
        if(i>=s.size()){
            ans.push_back(temp);
            
        }

        for(int j=i;j<s.size();j++){
            if(ispossible(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(s,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        solve(s,0);
        return ans;
    }
};