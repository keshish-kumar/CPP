//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = 1e9+7;
  long long count(int n,vector<int>& arr,int target,vector<vector<long long>>& dp){
      
    
      if(n==0) {
          if(target==0 && arr[n]==0) return 2;
          else if(arr[n]==target || target == 0) return 1;
          else
          return 0;
      }
      if(dp[n][target]!=-1) return dp[n][target];
      
      long long notpick = count(n-1,arr,target,dp)%mod;
      long long pick = 0;
      if(target >= arr[n])
        pick = count(n-1,arr,target-arr[n],dp)%mod;
        
    return dp[n][target] = (pick+notpick)%mod;
    
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        // count of subset sum we have to reduce this problem into that
        int sum =0;
      
       
        for(int i =0;i<n;i++){
            sum+=arr[i]; 
        }
        
        if((d+sum)%2!=0 || d>sum) return 0;
        
        int target = (d+sum)/2;
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        
       return count(n-1,arr,target,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends