//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int>& arr, int& k,int n,vector<int>& dp){
        if(n==0) return 0;
        
        int ans = 1e9;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                ans = min(ans,solve(arr,k,n-i,dp)+abs(arr[n]-arr[n-i]));
            }
        }
        return dp[n] = ans;
    }
  
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        vector<int> dp(arr.size()+1,-1);
        return solve(arr,k,arr.size()-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends