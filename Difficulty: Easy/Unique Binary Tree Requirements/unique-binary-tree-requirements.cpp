//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
       if((a==2 && b==3) || (a==3 &&b==2) ||(a==1 &&b==2) ||(a==2 &&b==1)) return true;
       else return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}
// } Driver Code Ends