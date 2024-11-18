//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        // code here
        // first wehav eto make ordering of the graph
        vector<int> indg(k,0);
        vector<vector<int>> adj(k);
        for(int k=0;k<n-1;k++){ // as. it have n words and we have to comapre each wrd
            string s1 = dict[k];
            string s2 = dict[k+1];
            int i=0,j=0;
            while(i<s1.size() && j<s2.size()){
                if(s1[i]!=s2[j]){
                    indg[s2[j]-'a']++;
                    adj[s1[i]-'a'].push_back(s2[j]-'a');
                    break;
                }
                i++;j++;
            }
        }
        
        // Now we have both adjacency matric and indegree we qill find the topological ordering
        string ans="";
        queue<int> q;
        for(int i=0;i<k;i++){
            if(indg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans += (char)(t+'a');
            for(auto it:adj[t]){
                indg[it]--;
                if(indg[it]==0) q.push(it);
            }
        }
       // cout<<ans<<endl;
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

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends