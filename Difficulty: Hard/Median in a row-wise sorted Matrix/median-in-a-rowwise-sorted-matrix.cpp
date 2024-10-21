//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(vector<vector<int>> &matrix, int R, int C, int mid){
        int ans =0;
        for(int i=0;i<R;i++){
            ans += upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return ans;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        int ans =0;
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<R;i++) high = max(high,matrix[i][C-1]); // this will store the maximum value of elemment present in vector
        while(low<=high){
            // Here the thought process is no of lmeent <=mid should be equal to n/2 nis R*C
            int mid = (low+high)/2;
            
            int n = solve(matrix,R,C,mid);
            int count= (R*C+1)/2;
            if(n>=count){
                ans = mid;
                high = mid-1;
            }
            else{
                
                low = mid+1;
            }
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends