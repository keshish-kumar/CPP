//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(vector<int>& arr , vector<int>& ans, int sum, int index){
        if(index==arr.size()){
            ans.push_back(sum);
            return ;
        }
        
        // take that element
        sum+=arr[index];
        solve(arr,ans,sum,index+1);
        sum-=arr[index];
        
        // not take
        solve(arr,ans,sum,index+1);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        // we can take recursion approach
        int sum =0;
        vector<int> ans;
        solve(arr,ans,sum,0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends