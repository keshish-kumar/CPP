//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int numCourses,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> (numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends