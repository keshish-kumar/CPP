//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
        // code here
        int count =0;
        int ans =-1;
        for(int i=0;i<arr.size();i++){
           // if(arr[i][count]==0) continue;
            int temp=count;
            for(int j=arr[0].size()-1 - count;j>=0;j--){
                if(arr[i][j]==1){
                    temp++;
                }
                else if(arr[i][j]==0){
                    break;
                }
            }
            if(temp>count){
                ans = i;
                count = temp;
            }
           // cout<<count<<endl;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends