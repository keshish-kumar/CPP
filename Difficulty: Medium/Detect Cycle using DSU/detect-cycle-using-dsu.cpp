//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    int find(int n , vector<int>& parent){
        if(parent[n] == n) return n;
        return find(parent[n],parent);
    }
    void unionf(int n1, int n2, vector<int>& parent){
        int x1 = find(n1,parent);
        int x2 = find(n2,parent);
        if(x1==x2) return;
        parent[x2] = x1;
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> parent(V);
	    for(int i=0;i<V;i++) parent[i] = i; // each is its own set
	    
	    // now apply dsu to find cycle by trversing each node
	    for(int i=0;i<V;i++){
	        
	        for(auto it:adj[i]){
	            if(it>i){
	                if(find(it,parent)==find(i,parent)) return 1;
	                unionf(i,it,parent);
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends