class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        // here we will use sliding window protocol
        int i=0,j=0;
        int maxi = 0;
        set<char> st;
        while(j<s.size()){
            if(st.find(s[j]) == st.end()){
                maxi = max(j-i+1,maxi);
                st.insert(s[j]);
                j++;
            }
            else{
                
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};