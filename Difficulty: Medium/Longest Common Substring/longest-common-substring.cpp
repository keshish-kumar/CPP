//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int substring(string s1, string s2, int n, int m , int count){
        if(n==0 || m==0) return count;
        
        if(s1[n-1] == s2[m-1]) return substring(s1,s2,n-1,m-1,count+1);
        
        return max(count,max(substring(s1,s2,n-1,m,0),substring(s1,s2,n,m-1,0)));
    }
    int longestCommonSubstr (string& s1, string& s2)
    {
        // your code here
        int n = s1.size();
        int m = s2.size();
        // return substring(s1,s2,n,m,0);
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        int ans =0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
                else{
                    if(s1[i-1]==s2[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                        ans = max(ans,dp[i][j]);
                    }
                    
                    else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends