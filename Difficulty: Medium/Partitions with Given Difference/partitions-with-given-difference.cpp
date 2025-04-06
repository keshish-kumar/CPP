//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& arr,int target, int i,vector<vector<int>>& dp){
        
       if(i==0){
           if(target == 0 && arr[i]==0) return 2;
           else if(target == 0 || arr[i]==target) return 1;
           else return 0;
       }
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick = solve(arr,target,i-1,dp);
        int pick = 0;
        if(target>=arr[i]){
            pick = solve(arr,target-arr[i],i-1,dp);
        }
        
        return dp[i][target] =  pick+notpick;
        
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        int n = arr.size();
        if((sum+d)%2 != 0 || d>sum) return 0;
        int target = (sum+d)/2;
        vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
        return solve(arr,target,n-1,dp);
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends