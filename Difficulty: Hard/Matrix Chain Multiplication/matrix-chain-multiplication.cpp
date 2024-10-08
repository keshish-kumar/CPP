//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int i, int j){
        if(i>=j) return 0;
        
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
            int temp = solve(arr,i,k)+solve(arr,k+1,j)+ (arr[i-1]*arr[k]*arr[j]);
            mini=min(mini,temp);
        }
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
       // return solve(arr,1,N-1);
        
        // Now we will go for 2d approach
        vector<vector<int>> dp(N,vector<int>(N,0));
        // firstw rititng base case
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                 int mini = INT_MAX;
                for(int k=i;k<j;k++){
                    int temp = dp[i][k]+dp[k+1][j]+ (arr[i-1]*arr[k]*arr[j]);
                    mini=min(mini,temp);
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