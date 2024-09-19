class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int i=0,j=0;
        int ans =0;
        while(j<s.size()){
            
            while(!st.empty() && st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);

            ans = max ( ans, (j-i+1));
            j++;

        }
        return ans;
    }
};