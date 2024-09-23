class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // either we can find cycle or topological sort.
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> (numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            for(auto it: adj[q.front()]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            q.pop();
        }
        if(ans.size()==numCourses) return true;
        else return false;
    }
};