//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>& arr, int i,int j,vector<vector<int>>& dp){
        if(i>=arr.size() ) return 0;
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int r = 0;
        if(j==-1 || 0!=j)
             r = arr[i][0]+solve(arr,i+1,0,dp);
        int f = 0;
        if(j==-1 || 1!=j)
             f = arr[i][1]+solve(arr,i+1,1,dp);
        int p = 0;
        if(j==-1 || 2!=j)
             p = arr[i][2]+solve(arr,i+1,2,dp);
        return dp[i][j+1] = max({r,f,p});
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solve(arr,0,-1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends