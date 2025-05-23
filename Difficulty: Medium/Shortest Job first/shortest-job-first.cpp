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
        vector<int> ct;
        ct.push_back(bt[0]);
        for(int i=1;i<bt.size();i++){
            ct.push_back(bt[i]+ct[i-1]);
        }
        long long sum=0;
        for(int i=0;i<bt.size();i++){
            ct[i] = ct[i]-bt[i];
            sum+=ct[i];
        }
        return sum/int(bt.size());
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