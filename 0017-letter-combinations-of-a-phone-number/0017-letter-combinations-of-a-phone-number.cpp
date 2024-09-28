class Solution {
public:
    void solve(string& digits, int index, map<int,string>& mp,string & temp,vector<string>& ans){
        if(index==digits.size()){
             ans.push_back(temp);
            return;
        }

       for(int i=0;i<mp[digits[index]-'0'].size();i++){
            string s = mp[digits[index]-'0'];
            temp.push_back(s[i]);
            solve(digits,index+1,mp,temp,ans);
            temp.pop_back();
       }

    }
    vector<string> letterCombinations(string digits) {
        map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        // now we have stored this in map; we will use vector<string> to store the answer
        vector<string> ans;
        if(digits.empty()) return ans;
        string temp;
        solve(digits,0,mp,temp,ans);
        return ans;
    }
};