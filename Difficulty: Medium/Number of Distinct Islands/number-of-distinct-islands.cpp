//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, vector<pair<int,int>>& v, int bi, int bj){
      
      vector<int> ii = {0,1,0,-1};
      vector<int> jj = {1,0,-1,0};
     
      for(int k=0;k<4;k++){
          int r = i+ii[k];
          int c = j+jj[k];
          if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && visited[r][c]==0 && grid[r][c]==1){
              visited[r][c] = 1;
              v.push_back({r-bi,c-bj});
              dfs(grid,r,c,visited,v,bi,bj);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        // w ewill use dfs here to find distict islan in this
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
       
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    visited[i][j]=1;
                   
                   vector<pair<int,int>> v;
                   v.push_back({i-i,j-j});
                 dfs(grid,i,j,visited,v,i,j);
                   st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends