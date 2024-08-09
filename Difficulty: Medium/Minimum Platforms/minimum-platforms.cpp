//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> q;
    	for(int i=0;i<n;i++){
    	    q.push({arr[i],'A'});
    	    q.push({dep[i],'D'});
    	}
    	
    	int ans =0,r = 0;
    	while(!q.empty()){
    	    pair<int,char> p = q.top();q.pop();
    	    if(p.second=='A') ans++;
    	    else ans--;
    	    r= max(r,ans);
    	    
    	}
    	
    	return r;
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends