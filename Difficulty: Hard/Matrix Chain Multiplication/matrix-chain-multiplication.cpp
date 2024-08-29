//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int arr[], int i, int j,vector<vector<int>>& dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+(arr[i-1]*arr[k]*arr[j]);
            mini = min(mini,temp);
        }
        
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // we have to fidnn the best optimal bracket we can do for minimal cost
    //   vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    //     return solve(arr,1,N-1,dp);
    
        vector<vector<int>> dp(N+1,vector<int>(N+1));
        
         // j should be row and i should be column
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<=N-1;j++){
                int mini = INT_MAX;
                 for(int k=i;k<=j-1;k++){
                     int temp = dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                mini = min(mini,temp);
                }
                dp[i][j] = mini;
            }

        }
        return dp[1][N-1];
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends