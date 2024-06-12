//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int sack(int n, int w, int val[], int wt[],vector<vector<int>>& dp){
        if(w==0) return 0;
        if(n<0) return 0;
        if(dp[n][w]!=-1) return dp[n][w];
        int notpick = sack(n-1,w,val,wt,dp);
        int pick = 0;
        if(w>=wt[n]){
            pick = val[n]+sack(n,w-wt[n],val,wt,dp);
            
        }
        
        return dp[n][w] = max(pick,notpick);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
        return sack(n-1,w,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends