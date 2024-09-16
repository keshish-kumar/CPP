class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ans;
    
        for(int i=0;i<strs.size();i++){
            string s= strs[i];
            sort(strs[i].begin(),strs[i].end());
            ans[strs[i]].push_back(s);
        }

        vector<vector<string>> a;
        for(auto it:ans){
            
            a.push_back(it.second);
        }
        return a;

    }
};