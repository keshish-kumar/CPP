//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  void solve(string & s1, string & s2, int i, int j, set<vector<int>>& st, vector<int> temp){
      if(j>=s2.size()){
          st.insert(temp);
          return;
      }
      if(i>=s1.size()){
          return;
      }
      
      if(s1[i]==s2[j]){
          temp.push_back(i);
          solve(s1,s2,i+1,j+1,st,temp);
          temp.pop_back();
      }
      
      solve(s1,s2,i+1,j,st,temp);
      
      
  }
    int countWays(string s1, string s2) {
        // code here
        
        set<vector<int>> st;
        vector<int> temp;
        // solve(s1, s2,0,0,st,temp);
        int mod = 1e9+7;
        vector<vector<long long>> dp(s1.size()+1,vector<long long>(s2.size()+1,0));
        
        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = 0;
                else{
                    if(s1[i-1]==s2[j-1]){
                        dp[i][j]= (dp[i-1][j-1]+dp[i-1][j])%mod;
                    }
                    else{
                        dp[i][j] = dp[i-1][j]%mod;
                    }
                }
            }
        }
        
        
        return dp[s1.size()][s2.size()]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends