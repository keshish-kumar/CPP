class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         // topological ordering
         vector<vector<int>> adj(n);

         vector<int> l(n,0);
         for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            l[pre[i][0]]++;
         }

         queue<int> q;
         for(int i=0;i<n;i++) if(l[i]==0) q.push(i);
        vector<int> ans;
         while(!q.empty()){
            ans.push_back(q.front());
            for(auto it:adj[q.front()]){
                
                l[it]--;
                if(l[it]==0) q.push(it);
            }
            q.pop();
         }

        return ans.size()==n?ans:vector<int>();
        
         
    }
};