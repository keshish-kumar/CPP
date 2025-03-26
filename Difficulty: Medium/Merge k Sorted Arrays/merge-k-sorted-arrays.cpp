//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> ans;
        int j=0;
        int i=0;
        while(i<k){
            pq.push({arr[i][j],i,j});
            i++;
        }
        while(!pq.empty()){
            i = pq.top()[1];
            j = pq.top()[2];
            ans.push_back(pq.top()[0]);
            pq.pop();
            if(j<k-1){
                pq.push({arr[i][j+1],i,j+1});
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
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends