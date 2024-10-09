//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dp[], int n, int k) {
        // code here
        // firts I will make adjacancy graph 
        // than I will apply topological sort to get the sequence
        
        vector<vector<int>> adj(k); // we are creating adjacency matrix to check topological sort
        vector<int> indegree(k,0);
        for(int i=0;i<n-1;i++){
            int j=0;
            string node1 = dp[i];
            string node2 = dp[i+1];
            while( j<node1.size() && j<node2.size()){
                if(node1[j]!=node2[j]){
                    adj[node1[j]-'a'].push_back(node2[j]-'a');
                    indegree[node2[j]-'a']++;
                    break;
                }
                j++;
            }
  
            
        }
        
        // Now we have to start from node were its indegree is 
        queue<int> q;
        for(int i=0;i<k;i++) if(indegree[i]==0) q.push(i);
        
        string ans ="";
        while(!q.empty()){
            int n = q.front();q.pop();
            ans += char('a'+n);
            for(auto it:adj[n]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        //cout<<ans<<endl;
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends