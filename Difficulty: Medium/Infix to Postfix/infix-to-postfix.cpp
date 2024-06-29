//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precendece(char op){
         if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
         if (op == '^') return 3;
        return 0;
    }
    string infixToPostfix(string s) {
        // Your code here
        string temp;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='a'&& s[i]<='z') ||(s[i]>='A'&& s[i]<='Z') ||(s[i]>='0'&& s[i]<='9') ){
                temp.push_back(s[i]);
            }
            else if (s[i] == '(') {
                st.push(s[i]);
                
            }
            else if(s[i]==')' ){
                while(!st.empty() && st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                
                st.pop();
                
                
            }
            else{
                while( !st.empty() && precendece(s[i])<=precendece(st.top()) ){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        return temp;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends