class Solution {
public:
    
    void letters(string digits, map<char,string>& mp, vector<string>& ans, string temp, int i){
         if(i>=digits.size()){
             if(temp.size()==digits.size())
             ans.push_back(temp);
             return;
         }
       
        for(int j=i;j<digits.size();j++){
            
            for(int k = 0; k<mp[digits[j]].size();k++){
                temp += mp[digits[i]][k];
                letters(digits,mp,ans,temp,j+1);
                temp.pop_back();
            }
            
        }
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        // First we have to create a structure which stores 2-9 all letters loke 2->"abc" ....
        // for this we will use vector which stroes pairs with integer and string
        map<char,string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> ans;
        if(digits.size()==0) return ans;
        string temp="";
        letters(digits,mp,ans,temp,0);
        return ans;
        
        
    }
};