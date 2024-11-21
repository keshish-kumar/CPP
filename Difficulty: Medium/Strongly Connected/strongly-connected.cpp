//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void DFS(stack<int>& st, vector<vector<int>>& adj, vector<int>& visited,int node){
	    
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(visited[it]==0){
	            DFS(st,adj,visited,it);
	        }
	    }
	    st.push(node);
	}
	void DFS2(int node, vector<int>& visited, vector<vector<int>>& newadj){
	    visited[node]=1;
	    for(auto it:newadj[node]){
	        if(visited[it]==0){
	            DFS2(it,visited,newadj);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // 1-> stack me topo order 
        // 2-> Revrse the ordere
        // 3-> Stack oprder me DFS call 
        
        //1
        stack<int> st;
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                DFS(st,adj,visited,i);
            }
        }
        
        // 2 revsre 
        vector<vector<int>> newadj(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                newadj[it].push_back(i);
            }
        }
        
        //3 stack order me dfs call
        for(int i=0;i<V;i++) visited[i]=0;
        int ans =0;
        while(!st.empty()){
            int n = st.top();
            st.pop();
            if(visited[n]==0){
                ans++;
                DFS2(n,visited,newadj);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends