//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	long long total(int arr[],int n, int sum,vector<vector<long long>>&dp){
	   // if(sum==0) return 1;
	    if(n==0){
	        if(sum == 0 && arr[n]==0) return 2; // THIS IS TO CEHCK IF 0 IS THERE OR NOT THAN WE WILL HAVE TWO CHOICES
	        else if(sum == 0 || arr[n]==sum) return 1;
	        else return 0;
	    }
	    
	    if(dp[n][sum]!=-1) return dp[n][sum];
	   
	    long long notpick = total(arr,n-1,sum,dp)%mod;
	    long long pick = 0;
	    if(sum>=arr[n])
	        pick = (total(arr,n-1,sum-arr[n],dp))%mod;
	   
	   return dp[n][sum] = (notpick+pick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{// Your code goes here
        
        vector<vector<long long>> dp(n+1,vector<long long>(sum+1,-1));
      long long ans =  total(arr,n-1,sum,dp)%mod;
       return ans%mod;
       
       // let us do tabulation approach
       
      // i represtn elements and j reperesent target
    //   vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    //   for(int i=0;i<=n;i++){
    //       for(int j=0;j<=sum;j++){
    //           if(j==0) return 1;
    //           else if(i==0) return 0;
    //           else{
    //               if(j>=arr[i-1]){
    //                   dp[i][j]= (dp[i-1][j-arr[i]]+dp[i-1][j])%mod;
    //               }
    //               else{
    //                   dp[i][j] = dp[i-1][j];
    //               }
    //           }
    //       }
    //   }
    //   return dp[n][sum]%mod;
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends