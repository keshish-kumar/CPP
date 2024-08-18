//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    map<char,int> mp1,mp2;
	    int ans=0;
	    for(auto it:pat)
	            mp2[it]++;
	   int j=0,i=0;
	   while(j<txt.size()){
	       
	      
	           
	       mp1[txt[j]]++;
	           
	       
	       if((j-i+1)==pat.size()){
	           
	           if(mp1==mp2) ans++;
	           
	           mp1[txt[i]]--;
	           if(mp1[txt[i]]==0) mp1.erase(txt[i]);
	           
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