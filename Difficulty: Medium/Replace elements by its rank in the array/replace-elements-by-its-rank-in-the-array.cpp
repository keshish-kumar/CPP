//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

            vector<int> ans(N,0);
            priority_queue<int,vector<int>,greater<int>> q;
            for(int i=0;i<N;i++){
                q.push(arr[i]);
            }
            
           map<int,int> mp;
           int i=1;
           while(!q.empty()){
               if(mp.find(q.top())==mp.end()){
                   mp[q.top()]=i;
                   i++;
               }
               q.pop();
               
           }
           for(int i=0;i<N;i++){
               int rank = mp[arr[i]];
               ans[i] = rank;
           }
           
           return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends