//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> temp(n,1);
        vector<int> index(n);
        index[0] = -1;
        for(int i=1;i<n;i++){
            int maxi = 1;
            index[i] = i;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(maxi<(temp[i]+temp[j])){
                        maxi = temp[i]+temp[j];
                        index[i] = j;
                    }
                }
            }
            temp[i] = maxi;
        }
        
        int ind=0;
        int maxi = 1;
        
        for(int i=0;i<n;i++){
            
            if(maxi< temp[i]){
                maxi = temp[i];
                ind = i;
            }
           // cout<<index[i]<<" ";

        }
        
        //cout<<endl;
        
        vector<int> ans;
       while(true){
            ans.push_back(arr[ind]);
            if(index[ind]==-1 || index[ind]==ind) break;
            ind = index[ind];
          
       }
       
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends