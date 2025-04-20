class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans =0;
        int i=0,j=0;
        unordered_set<char> st;
        while(i<=j && j<s.size()){

            while(i<j && st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++; 
            }

            st.insert(s[j]);
            j++;
            ans = max(ans,(j-i));
        }
        return ans;
    }
};