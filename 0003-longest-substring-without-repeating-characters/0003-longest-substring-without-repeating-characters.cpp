class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i=0;
        int j=0;
        int ans = 0;
        while(i<s.size()){
            while(i<s.size() && st.find(s[i])==st.end()){
                st.insert(s[i]);
                i++;
            }
            ans = max(ans,(int)st.size());
            while(j<i && st.find(s[i])!=st.end()){
                st.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};