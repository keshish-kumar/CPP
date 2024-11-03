//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        // we have to take queue and apply dfs in that
       
        int ans=0;
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==2){
                     q.push({i,j});
                     
                }
            }
        }
        vector<int> ii = {-1, 0, 1, 0};
        vector<int> jj = {0, 1, 0, -1};
        while(!q.empty()){
            int n = q.size();
            bool flag = false;
            while(n--){
                int ni = q.front().first;
                int nj = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int i = ii[k]+ni;
                    int j = jj[k]+nj;
                    if(i>=0 && j>=0 && i<mat.size() && j<mat[0].size() && mat[i][j]==1){
                        q.push({i,j});
                        mat[i][j] = 2;
                        flag = true;
                    }
                }
            }
            if(flag==true) ans++;
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends