//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int sack(int n, int w, int val[],vector<vector<int>>& dp){
        if(w==0) return 0;
        if(n==0) return 0;
        if(dp[n][w]!=-1) return dp[n][w];
        int notpick = sack(n-1,w,val,dp);
        int pick = 0;
        if(w>=n){
            pick = val[n-1]+sack(n,w-n,val,dp);
            
        }
        
        return dp[n][w] = max(pick,notpick);
    }
    int cutRod(int val[], int n) {
        //code here
      
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       
       return sack(n,n,val,dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends