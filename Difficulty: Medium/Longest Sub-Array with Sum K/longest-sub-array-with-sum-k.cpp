//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
    int ans = 0; 
    int sum = 0; 
    map<int, int> mp; 
    mp[0] = -1; // Initialize for subarrays that sum to k at the start

    for (int j = 0; j < n; j++) {
        sum += a[j]; // Update the cumulative sum

        // Check if there's a subarray with sum equal to k
        if (mp.find(sum - k) != mp.end()) {
            ans = max(ans, j - mp[sum - k]); // Update the maximum length
        }

        // Only insert the sum if it's not already present (to maintain the earliest index)
        if (mp.find(sum) == mp.end()) {
            mp[sum] = j; // Store the first occurrence of this sum
        }
    }
    
    return ans; 

    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends