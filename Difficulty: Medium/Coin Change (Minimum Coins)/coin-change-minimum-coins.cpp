//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
  int solve(vector<int>& coins, int sum, int index){
      if(sum==0) return 0;
      if(index>=coins.size()) return 1e9;
      
      // multiple pick 
      int pick = INT_MAX;
      if(sum>=coins[index]){
        pick = 1+solve(coins,sum-coins[index],index);
      }
      int notpick = solve(coins,sum,index+1);
      return min(pick,notpick);
  }
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        // multiple pick can be perfomrbe=ed
        // int n = solve(coins,sum,0);
        // return n==1e9?-1:n;
        
        vector<int> dp(sum+1,1e9);
        dp[0] = 0; // sum 0 require o coins
        for(int i=1;i<=coins.size();i++){
            vector<int> temp(sum+1,1e9);
            temp[0] = 0;
            for(int j=1;j<=sum;j++){
                int pick = 1e9;
                if(j>=coins[i-1]){
                    pick = 1+temp[j-coins[i-1]]; // same index only
                }
                int notpick = dp[j];
                temp[j] = min(pick,notpick);
            }
            dp = temp;
        }
        
        return dp[sum]==1e9?-1:dp[sum];
        
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends