//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<vector<int>>& ans, int n,int index,vector<vector<int>>& dp){
      if(n>=ans.size()){
          return 0;
      }
      
      int maxi = 0;
      if(dp[n][index] !=-1) return dp[n][index];
      for(int i=0;i<3;i++){
          if(i!=index){
              maxi=max(maxi,ans[n][i]+solve(ans,n+1,i,dp));
          }
      }
      return dp[n][index] = maxi;
  }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return solve(arr,0,3,dp);
        
        
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
    }
    return 0;
}
// } Driver Code Ends