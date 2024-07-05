//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        // code here 
        // Approach 1 all rows 0 and columns 1 except of diagonal colukns 
        
        int ans =-1;
        for(int i=0;i<n;i++){
            
            // for column all should be 1
            int count =0;
            for(int j=0;j<n;j++){
                if(i!=j && arr[j][i] == 1){
                    count++;
                }
            }
            // for row all should be 0's
            int row = 0;
            for(int j=0;j<n;j++){
                if(arr[i][j] == 1) row++;
            }
            
            if(count == n-1 && row ==0) ans = i;
          
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends