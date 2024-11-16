class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            int n = num[i];
            while(!st.empty() && k>0 && st.top()>n){
                st.pop();
                k--;
            }
            st.push(n);
        }
        while(k--){
            st.pop();
        }
        string s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        s = s.substr(i);
        if(s=="") return "0";
        return s;
       
    }
};