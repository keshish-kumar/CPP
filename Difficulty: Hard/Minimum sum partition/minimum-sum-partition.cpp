//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

  public:
  
  int solve(int arr[], int n, int target,vector<vector<int>>& dp){
      if(target == 0){
          return 1;
      }
      if(n == 0){
          return 0;
      }
      
      if(dp[n][target]!=-1) return dp[n][target];
      int ans1 =0;
      if(arr[n-1]<=target){
          ans1 = solve(arr,n-1,target-arr[n-1],dp);
      }
      int ans2 = solve(arr,n-1,target,dp);
      
      
      dp[n][target]=ans1||ans2;
      return dp[n][target];
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	   int target = 0;
	   for(int i=0;i<n;i++){
	       target += arr[i];
	   }
	   
	    int sum = target; // Cast to double to allow floating-point division
        target = ceil((double)sum / 2);
	   
	  /* 
	   for(int i=0;i<=target;i++){
	       vector<vector<int> > dp(n+1,vector<int>(i+1,-1));
	        if(solve(arr,n,i,dp))
	            ans = min(ans,abs(sum-(2*i)));
	        
	   }*/
	 int ans = INT_MAX;  
	vector<vector<int>> dp(n+1,vector<int>(target+1)); // paas integer inplace of recursion
     
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(arr[i-1]<=j ){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j]=(dp[i-1][j]);
            }
        }
    }
    
    for(int i=0;i<=target;i++){
        if(dp[n][i]) ans = min(ans,abs(sum-(2*i)));
    }
	   return ans;
	} 
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends