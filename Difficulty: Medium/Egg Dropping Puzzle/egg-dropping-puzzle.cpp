//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int eggDrop(int n, int k) 
    {
        // your code here
        // Here we have to asssume worst value f which will take maximum steps to find
       if(k==0 || k==1){
           return k; // only f posisblity to check
       }
       if(n==1) return k; // we will start thrwinf from down floor one by one
       
       vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        // Base cases initialization
    for (int i = 1; i <= k; i++) {
        dp[i][1] = i; // 1 egg, i floors requires i drops
    }
    
    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1; // Only 1 floor requires 1 drop regardless of eggs
    }

       for(int i=2;i<=k;i++){
           for(int j=2;j<=n;j++){
               int ans = INT_MAX;
                for(int f=1;f<=i;f++){
                     //int temp = 1+max(eggDrop(n-1,f-1),eggDrop(n,k-f)) ; // one is if egg broke tha cehck fom down of that f if it doesnot break than check above that floor
                     int temp = 1+max(dp[f-1][j-1],dp[i-f][j]);
                     ans = min(ans,temp);
                 }
        
        dp[i][j] = ans;
           }
       }
       
      return dp[k][n];
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends