//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int jump(vector<int>& height, int n, int k,vector<int>& dp){
        
        if(n==0) return 0;
        
        int minSteps=INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<=k;i++){
            if(n-i >=0 ){
                int temp = jump(height,n-i,k,dp) + abs(height[n]-height[n-i]);
                minSteps = min(minSteps,temp);
            }
            else
                break;
        }
        dp[n] = minSteps;
        return dp[n];
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        return jump(height,n-1,k,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends