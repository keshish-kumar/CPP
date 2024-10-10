class Solution {
public:
    int numberOfSubstrings(string s) {
        
       
        int j=0;
        int i=0;
        int n = s.size();
        map<char,int> mp;
        int ans =0;
        while(j<s.size()){
            mp[s[j]]++;
            // while(mp.find('a')!=mp.end() && mp.find('b')!=mp.end() && mp.find('c')!=mp.end()){
            //     ans+=  1+(n-j);
            //     mp[s[i]]--;
            //     if(mp[s[i]]==0) mp.erase(mp[s[i]]);
            //     i++;
            // }

            // j++;
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
            // Add the valid substrings
            ans += (n - j);
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
        }

        return ans;
    }
};