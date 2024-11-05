class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        for(int i=n-1;i>=0;i--){
            if(expression[i]=='!' || expression[i]=='|' || expression[i]=='&'){
                bool t = false;
                bool f = true;
                while(!st.empty() && st.top()!=')'){
                        if(st.top()=='t') t = true;
                        if(st.top()=='f') f = false;
                        st.pop();
                }
                if(st.top()==')')
                    st.pop();
                if (expression[i] == '!') {
                    st.push(t ? 'f' : 't'); // Negate the result
                } else if (expression[i] == '|') {
                    st.push(t || f ? 't' : 'f'); // At least one true
                } else if (expression[i] == '&') {
                    st.push(t && f ? 't' : 'f'); // All must be true
                }
            }
            else{
                if(expression[i]=='t'||expression[i]=='f' || expression[i]==')') st.push(expression[i]);
            }
        }
        return st.top()=='t';
    }
};