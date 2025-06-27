class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> indegre(n);
        for(int i=0;i<pre.size();i++){
            int u  = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
            indegre[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegre[it]--;
                if(indegre[it]==0) q.push(it);
            }
        }

        for(int i=0;i<n;i++)
            if(indegre[i]!=0) return {};
        return ans;
    }
};