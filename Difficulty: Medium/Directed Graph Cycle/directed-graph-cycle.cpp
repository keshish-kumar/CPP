//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], vector<int> &visited,int i,set<int>& st){
        visited[i]=1;
        st.insert(i);
        for(auto it:adj[i]){
            if(!visited[it]){
                if(dfs(adj,visited,it,st)) return true;
            }
            else if(st.find(it)!=st.end())
                    return true;
        }
        st.erase(i);
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
       
       vector<int> visited(V,0);
       set<int> st;
        for(int i=0;i<V;i++){
             
            if(!visited[i]){
                if(dfs(adj,visited,i,st)) return true;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends