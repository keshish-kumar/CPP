//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
     int numberOnes(vector<int>arr , int m){
            int start = 0;
            int end = m-1;
            while(start < end){
                int mid = start + (end - start)/2;
                if(arr[mid] == 0){
                    start+=1;
                }
                else{
                    end = mid;
                }
            }
            if(end == m-1 and arr[m-1] == 0){
                return 0;
            }
            else{
                return (m-end);
            }
        }
        int maxOnes (vector <vector <int>> &Mat, int n, int m)
        {
            // your code here
             int prevCount = 0;
            int ans = 0;
            for(int i = 0 ; i < n ; i++){
                int a = numberOnes(Mat[i] , m);
                if(a > prevCount){
                    ans = i;
                }
                prevCount = max(a , prevCount);
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends