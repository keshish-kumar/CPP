class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> sc(26,0);
        vector<int> tc(26,0);
        for(int i=0;i<s.size();i++){
            sc[s[i]-'a']++;
            tc[t[i]-'a']++;
        }
        return sc == tc ? true:false;
    }
};