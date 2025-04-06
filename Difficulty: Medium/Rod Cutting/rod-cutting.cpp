//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(vector<int>& price, int n, int i,vector<vector<int>>& dp){
        
        if(i==0 || n==0) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        int notpick = solve(price,n,i-1,dp);
        int pick = 0;
        if(i<=n){
            pick = price[i-1] + solve(price,n-i,i,dp);
        }
        return dp[i][n] = max(pick,notpick);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,n,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends