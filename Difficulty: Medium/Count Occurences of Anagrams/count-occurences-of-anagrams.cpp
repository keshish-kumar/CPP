//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string txt, string pat) {
	    // code here
	   map<char, int> mp;
	    int ans=0;
	    for(int i=0;i<txt.size();i++){
	        mp[txt[i]]++;
	    }
	    int count = mp.size();
	    int i=0,j=0;
	
	    while(j<pat.size()){
	       // cout<<i<<" "<<j<<endl;
	        // first we havce to check wethher that elemet is present in map or not
	        if(mp.find(pat[j])!=mp.end()){
	            mp[pat[j]]--;
	            if(mp[pat[j]]==0) count--;
	        }
	        
	        // if the size is equals to window size
	        if((j-i+1)==txt.size()){
              
	            if(count==0) ans++;
	            if(mp.find(pat[i])!=mp.end()){  if(mp[pat[i]]==0)count++; mp[pat[i]]++;}
	            i++;
	        }
	        j++;
	      
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends