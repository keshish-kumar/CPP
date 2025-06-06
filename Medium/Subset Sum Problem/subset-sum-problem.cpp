//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool subset(vector<int> arr , int sum , int n,vector<vector<int>>& dp){
        if(sum==0) return true;
        //if(n==0) return (arr[n]==sum);
        if(n<0) return 0;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        bool nottake = subset(arr,sum,n-1,dp);
        bool take = false;
        if(sum >= arr[n]){
            take = subset(arr,sum-arr[n],n-1,dp);
        }
       dp[n][sum] = nottake||take ;
       if(dp[n][sum]) return true;
       else return false;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        // vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        
        // return subset(arr,sum,arr.size()-1,dp);
        
         vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
        for(int i=0;i<=arr.size();i++)
            dp[i][0] = true;
            
        
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                   dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; // taken or noot taken
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
            }
            
        }
        return dp[arr.size()][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends