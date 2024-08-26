//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool solve(string pattern, int n , string str, int m,vector<vector<int>>& dp){
        if(n==0 && m>0) return false;
        if(n==0 && m==0) return true;
        if(m==0 && n>0){
            bool flag = true;
            for(int ii=n-1;ii>=0;ii--){
                if(pattern[ii]!='*') {
                    flag=false;
                    break;
                }
            }
            return dp[n][m] = flag;
        }
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if((pattern[n-1]==str[m-1]) || pattern[n-1]=='?'){
            return dp[n][m] = solve(pattern,n-1,str,m-1,dp);
        }
        else if(pattern[n-1]=='*'){
            return dp[n][m] = solve(pattern,n,str,m-1,dp)||solve(pattern,n-1,str,m,dp);
        }
        else
        return dp[n][m] = false;
    }
    
    int wildCard(string pattern, string str) {
        // code here
        int n = pattern.size();
        int m = str.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         if(solve(pattern,n,str,m,dp)) return 1;
         else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends