class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        int ans = INT_MAX;
        int count = t.size();
        int i = 0, j = 0;
        int p = 0;
        while (i < s.size()) {
            while (count > 0 && i < s.size()) {
                if (mp.find(s[i]) != mp.end() && mp[s[i]] > 0) {
                    count--;
                }
                mp[s[i]]--;
                i++;
            }
            while (count == 0) {
                if (i - j < ans) {
                    ans = i - j;
                    p = j;
                }
                mp[s[j]]++;
                if (mp[s[j]] > 0)
                    count++;
                j++;
            }
        }

        if (ans == INT_MAX)
            return "";
        return s.substr(p, ans);
    }
};