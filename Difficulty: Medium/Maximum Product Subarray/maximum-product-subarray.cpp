//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long maxi = -1e9;
	    long long psum = 1;
	    for(int i=0;i<n;i++){
	        psum = psum*arr[i];
	        maxi = max(maxi,psum);
	        if(psum==0) psum = 1;
	        
	    }
	    long long ssum=1;
	    for(int i=n-1;i>=0;i--){
	        ssum = ssum*arr[i];
	         maxi = max(maxi,ssum);
	        if(ssum==0) ssum = 1;
	       
	    }
	    return maxi;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends