//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    string rem(string s){
        string temp;
        int i=0;
        while(i<s.size()){
            if(i+1 < s.size() && s[i]==s[i+1]){
                while(i+1<s.size() && s[i]==s[i+1]){
                    i++;
                }
            }
            else{
                temp.push_back(s[i]);
            }
            i++;
        }
        return temp;
    }
    string rremove(string s) {
        // code here
        string s1;
        while(s1.size() != s.size()){
                s1 = s;
                s = rem(s);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends