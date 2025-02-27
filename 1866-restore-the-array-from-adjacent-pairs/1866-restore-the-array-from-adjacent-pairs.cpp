class Solution {
public:
    void dfs(map<int,int>& visited, int node,  vector<int> & ans,map<int,vector<int>>& mp){
        visited[node]=1;
        ans.push_back(node);
        // Now we will lok into that node vector
        for(auto it:mp[node]){
            if(visited[it]==0){
                dfs(visited,it,ans,mp);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> mp;
        for(int i=0;i<adjacentPairs.size();i++){
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        // Now we got the adjacency list we will plot the graph
        // first we need to find the source node single connection 
        int node;
        for(auto it:mp){
            if(it.second.size()==1) {node = it.first; break;};
        }
        // Now we got the node we will now travrese in dfs
        //vector<int> visited(mp.size(),0);
        // instead of vsited vector we will use map for visited
        map<int,int> visited;
        for(auto it:mp){
            visited[it.first]=0;
        }
        vector<int> ans;
        dfs(visited,node,ans,mp);
        return ans;
    }
};