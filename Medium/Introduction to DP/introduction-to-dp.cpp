//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
      long long int helper(int n,vector<long long int> &dp,long long int MOD){
        
        // if(n==0) return dp[n] =  n;
        // if(n==1) return dp[n] =  n;
        if(n<=1) return dp[n] = n; 
        
        
        if(dp[n]!=-1) return dp[n]%MOD;
        
        return dp[n] = (helper(n-1,dp,MOD)+helper(n-2,dp,MOD))%MOD;
        
    }
  public:
  

  
    long long int topDown(int n ) {
        
        long long int MOD = 1e9+7;
        vector<long long int> dp(n+1,-1);
        
        return helper(n,dp,MOD);
        
    }
  
    
    
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp1(n+1,-1); 
        dp1[0] = 0;
        dp1[1] = 1;
        for(int i=2;i<=n;i++){
            dp1[i] = (dp1[i-1]+dp1[i-2])%1000000007;
        }
            
        return dp1[n];
    }

//     long long int solve(int n , vector<long long int > &dp , long long int mod){
//         if(n<=1) return dp[n]=n;
//         if(dp[n] !=-1) return dp[n]%mod;
//         return dp[n]=(solve(n-1,dp,mod)+solve(n-2,dp,mod))%mod; 
//     }
//   public:
//     long long int topDown(int n) {
//         long long int mod= 1e9+7;
//         vector<long long int > dp(n+1 , -1); // n+1 so that we do not have problem in 1 based indexing
//         return solve(n,dp,mod);
//     }
//     long long int bottomUp(int n) {
//          long long int mod= 1e9+7;
//         vector<long long int > dp(n+1 , -1); // n+1 so that we do not have problem in 1 based indexing
//         dp[0]=0;
//         dp[1]=1;
        
//         for(int i=2 ;i<=n;i++){
//              dp[i]=(dp[i-1]+dp[i-2])%mod;
//             }
      
//         return dp[n]%mod;
//     }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends