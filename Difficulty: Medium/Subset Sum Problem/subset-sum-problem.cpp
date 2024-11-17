//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool solve(vector<int>& arr, int target, int i,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i>=arr.size()) return false;
        if(dp[target][i]!=-1) return dp[target][i];
        bool l = false;
        if(target>=arr[i]){
            l = solve(arr,target-arr[i],i+1,dp);
        }
        bool r = solve(arr,target,i+1,dp);
        return dp[target][i] = l||r;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(target+1,vector<int>(arr.size(),-1));
        return solve(arr,target,0,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends