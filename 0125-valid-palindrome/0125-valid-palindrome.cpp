class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        // after converting it to lower we can use stack 
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) st.push(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z')  || (s[i]>='0' && s[i]<='9')){
            if(st.top()!= s[i]) return false;
            cout<<st.top()<<endl;
            st.pop();
        }
        }
        return true;
    }
};