//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[] , int n,int w,vector<vector<int>>& dp){
      if(w==0) return 0;
      if(n==0){
          return 0;
      }
      if(dp[n][w]!=-1) return dp[n][w];
       int notpick = solve(price,n-1,w,dp);
       
       int pick = 0;
       
       if(w>=n)
            pick = price[n-1]+solve(price,n,w-n,dp);
            
        return dp[n][w] = max(notpick,pick);
     
      
  }
    int cutRod(int price[], int n) {
        //code here
        //try to pcik length in all possible way. 5+3 will give me that length.
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
    }
    return 0;
}
// } Driver Code Ends