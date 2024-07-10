//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  // thisquestion now can be converted into left and right minimum

  
  
  
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
       int ans = 0;
       for(int i=0;i<m;i++)
            ans = max(ans,mat[0][i]);
        for(int j =0 ; j<n;j++) ans  = max(ans,mat[j][0]);
       for(int i=1;i<n;i++){
           for(int j=1;j<m;j++){
               if(mat[i][j]==0) mat[i][j] = 0;
               else 
                mat[i][j] += min(mat[i-1][j],min(mat[i-1][j-1],mat[i][j-1]));
               ans  = max(ans,mat[i][j]);
           }
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
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends