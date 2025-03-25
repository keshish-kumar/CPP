//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(vector<vector<int>>& adj, vector<int>& visited,int node, int parent){
        visited[node] = 1;
        
        for(auto it: adj[node]){
           if(visited[it] == 0) {if(solve(adj,visited,it,node)) return true;}
           else if (it != parent) return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited(n,0);
        // lets start with 0 node
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(solve(adj,visited,i,-1)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends