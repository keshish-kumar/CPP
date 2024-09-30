//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long solve(int n , int mid){
	    long long  ans  = 1;
	    for(int i=1;i<=n;i++)
	        {ans *= mid;
	            if(ans>mid) break;
	        }
	   return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here. 
	    int low = 1;
	    int high = m;
	   
	    while(low<=high){
	        long long mid = low + (high-low)/2;
	        
	       //long long temp = solve(n,mid);
	       long long temp = 1;
	       for(int i=1;i<=n;i++){
	           temp *= mid;
	           if(temp>m) break;
	       }
	        if(temp==m) return mid;
	        if(temp<m) low = mid+1;
	        else high = mid-1;
	    }
	    
	    return -1;
	}  
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends