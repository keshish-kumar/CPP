//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool ispossible(vector<vector<int>>& adj, int i,vector<int>& color,int c){
      for(auto it:adj[i]){
          if(color[it]==c) return false;
      }
      return true;
  }
  bool solve(vector<vector<int>>& adj, int i,vector<int>& color, int m){
      
      if(i==adj.size()) return true;
      for(int c=1;c<=m;c++){
          if(ispossible(adj,i,color,c)){
              color[i]=c;
              if(solve(adj,i+1,color,m)) return true;
              color[i]=0;
          }
      }
      return false;
      
  }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        vector<int> color(v,0);
        return solve(adj,0,color,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends