//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string& str, int start,int end){
        if(start==end) return true;
        while(start<end){
            if(str[start++]!=str[end--]) return false;
        }
        return true;
    }
    int solve(string & str, int i,vector<int>& dp){
        if(i>=str.size()) return 0;
        int ans = INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int k = i;k<str.size();k++){
            if(isPalindrome(str,i,k)){
                ans = min(ans,1+solve(str,k+1,dp));
            }
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        vector<int> dp(str.size(),-1);
        return solve(str,0,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends