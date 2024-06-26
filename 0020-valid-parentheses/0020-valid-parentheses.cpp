         class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(st.empty()) return false; // No matching opening bracket
                char top = st.top();
                if((s[i] == ')' && top != '(') ||
                   (s[i] == ']' && top != '[') ||
                   (s[i] == '}' && top != '{')) {
                    return false; // Mismatched brackets
                }
                st.pop(); // Match found, pop the stack
            }
            
        }
      
        return st.empty();
    }
};
        
     