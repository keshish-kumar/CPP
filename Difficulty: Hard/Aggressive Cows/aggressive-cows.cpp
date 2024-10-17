//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int cows(int mid, vector<int>& stalls){
        int count=1;
        int prev = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if((stalls[i]-prev)>=mid){
                count++;
                prev = stalls[i];
            }
        }
        return count;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        // first we nee to sort the stalls 
        sort(stalls.begin(),stalls.end());
        int ans=0;
        int low = 1,high = *max_element(stalls.begin(),stalls.end());
        while(low<=high){
            int mid= (low+high)/2;
            int no = cows(mid,stalls); // will give wether with the difference mid it will provide k no. cows or not
            if(no>=k){low=mid+1;ans=max(ans,mid);}
            else high = mid-1;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends