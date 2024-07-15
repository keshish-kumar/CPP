//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s>(9*d)) return "-1";
        bool sum = false;
        string st="";
        while(d>0){
            if(sum && d==1){
               
                st = '1' + st;
            }
            else if(sum && d>1){
                st = '0'+st;
            }
            else if(s>9){
                st = '9' + st;
                s = s-9;
            }
            else if( d>1){
               
                st =  to_string(s - 1)+st;
                sum=true;
            }
            else{
             
                st = to_string(s )+st;
            }
            
            
            d--;
        }
        
        return st;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends