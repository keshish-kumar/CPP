//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(vector<vector<int>>& adj, vector<int> visited, int i){
        visited[i] = 1;
        for(auto it : adj[i]){
            if(visited[it]==1) return true;
            else{
                if(solve(adj,visited,it)) return true;
            }
        }
        return false;
        
    }
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        // for direvted we need oonly visited to check wether we have visited that or not.
        vector<int> visited(adj.size(),0);
        
        for(int i=0;i<adj.size();i++){
            if(visited[i]==0){
                if(solve(adj,visited,i)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends