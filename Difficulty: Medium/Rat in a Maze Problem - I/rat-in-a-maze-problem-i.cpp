//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i, int j, string &temp, vector<string>& ans, vector<vector<int>>& visited,int n,vector<vector<int>> &m){
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        visited[i][j] = 1;
        // up
        if(i-1>=0 && visited[i-1][j]!=1 &&m[i-1][j]==1){
            temp.push_back('U');
            
            solve(i-1,j,temp,ans,visited,n,m);
            temp.pop_back();
            
        }
        //down
        if(i+1<n && visited[i+1][j]!=1 && m[i+1][j]==1){
            temp.push_back('D');
            
            solve(i+1,j,temp,ans,visited,n,m);
            temp.pop_back();
            
        }
        //left j-1
        if(j-1>=0 && visited[i][j-1]!=1 && m[i][j-1]==1){
            temp.push_back('L');
            
            solve(i,j-1,temp,ans,visited,n,m);
            temp.pop_back();
            
        }
        //rightj+1
        if(j+1<n && visited[i][j+1]!=1 && m[i][j+1]==1){
            temp.push_back('R');

            solve(i,j+1,temp,ans,visited,n,m);
            temp.pop_back();
            
        }
        visited[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        // here also we need to fidn what are all the possible path that have been followd
        
        // visited array
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
        vector<string> ans;
        string temp;
        solve(0,0,temp,ans,visited,n,m);
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends