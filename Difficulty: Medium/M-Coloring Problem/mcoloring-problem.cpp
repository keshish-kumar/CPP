//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isposible( vector<vector<int>>& adj, vector<int>& color,int index,int col){
      
      for(auto it:adj[index]){
          if(color[it]==col) return false;
      }
      return true;
  }
    
    bool solve(vector<vector<int>>& adj, vector<int>& color, int index){
        if(index==adj.size()) return true;
        
        for(int i=1;i<=color.size();i++){ // we will try with all the possiblity of colors from strarting node
            if( isposible(adj,color,index,i)){ // it will check wether color[i] is possible or not
                color[index] = i;
                if(solve(adj,color,index+1)) return true;
                color[index] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(n); 
        
        // Here we will get adjacency matrix
        for(int i=0;i<n;i++){
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        
        // we will apply backtracking to check for every possible solutions.
        vector<int> color(m,0);
        return solve(adj,color,0);
        
            
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
             << endl; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends