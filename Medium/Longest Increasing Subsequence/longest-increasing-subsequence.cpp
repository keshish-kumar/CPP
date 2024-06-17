//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
   
    
    // int lower_bound(int low, int high,  int n,vector<int> temp){
    //     int ans = -1;
    //     while(low<=high){
    //         int mid = (low+high)/2;
            
    //         if(temp[mid]==n) return mid;
    //         else if(temp[mid] > n){
    //             high = mid-1;
    //         }
    //         else{
    //             ans = mid;
                
    //             low = mid+1;
    //         }
    //     }
    //     return ans;
    // }
    
    
    int longestSubsequence(int n, int nums[])
    {
    
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i<n;i++ ){
        
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int index = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[index] = nums[i];
            
        }
        
    }
    
    return temp.size();
   
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends