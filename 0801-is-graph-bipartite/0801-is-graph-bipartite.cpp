class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> visited(graph.size(),-1);
        vector<int> color(graph.size(),-1);
       
        for(int i=0;i<graph.size();i++){
            if(visited[i]==-1){
                queue<int> q;
            q.push(i);
             color[i]=0;
         visited[i]=1;
             while(!q.empty()){
            int node = q.front();q.pop();
            //visited[node]=1;
            for(auto it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    if(visited[it]!=1){
                        q.push(it);
                    }
                    visited[it]=1;
                }
                else if(color[it]==color[node]) return false;
            }
        }
            }
             
        }
       
        return true;
    }
};