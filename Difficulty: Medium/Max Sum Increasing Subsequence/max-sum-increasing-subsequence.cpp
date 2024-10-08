//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<pair<int,int>> v(n,{1,0});
	    for(int i=0;i<n;i++)
	        v[i].second = arr[i];
	    // first we will calculate the maximum sum increasing subsequnece and than store that 
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                v[i].first = max(v[i].first,v[j].first+1);
	                v[i].second = max(v[i].second,v[j].second+arr[i]);
	            }
	        }
	    }
	    int ans =0;
	    for(int i=0;i<n;i++)
	        ans=max(ans,v[i].second);
	   return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends