//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        
        long long exittime=0;
        vector<int> ct;
        for(int i=0;i<bt.size();i++){
                exittime += bt[i];
                ct.push_back(exittime);
        }
        
        long long ans=0;
        for(int i=0;i<bt.size();i++){
            ans += abs(bt[i]-ct[i]);
        }
        ans = ans/bt.size();
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends