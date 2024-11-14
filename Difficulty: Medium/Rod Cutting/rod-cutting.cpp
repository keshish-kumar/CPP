//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[], int n, int w,vector<vector<int>>& dp){
      if(n==0 || w==0) return 0;
      if(dp[n][w]!=-1) return dp[n][w];
      int l = solve(price,n-1,w,dp);
      int r = 0;
      if(w>=n){
          r = price[n-1]+solve(price,n,w-n,dp);
      }
      
      return dp[n][w]=max(l,r);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,n,dp);
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
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends