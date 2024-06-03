//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    // memoization
    int path(vector<int>& heights, int n , vector<int> &dp){
        
       if(n==0) return dp[n] = 0;
       if(n==1) return dp[n] = abs(heights[1]-heights[0]);
        
        
       if(dp[n]!=-1) return dp[n];
        
        
       return dp[n] = min(path(heights,n-1,dp)+abs(heights[n]-heights[n-1]) ,path(heights,n-2,dp)+abs(heights[n]-heights[n-2]));
       
       
    }
  
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        
        return path(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends