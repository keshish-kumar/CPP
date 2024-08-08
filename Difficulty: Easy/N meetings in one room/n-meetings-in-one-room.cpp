//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; 
        for(int i=0;i<n;i++){
            q.push({end[i],start[i]});
        }
        
        int str = 0,ed=0,ans=0;
        
        while(!q.empty()){
            pair<int,int> p = q.top();q.pop();
            if(p.second > ed){
                ans++;
                str=p.second;
                ed = p.first;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends