//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        // here we will apply binary seaarch on answer
        // let x be the arr1 and y be the arr2
        // x1<=y2 && x2<=y1
        // low and high
        if(arr1.size()>arr2.size()) swap(arr1,arr2);
        int x = arr1.size(), y = arr2.size();
      
        int low = max(0,k-y), high =min(x,k);
        
        while(low<=high){
            int mid = (low+high)/2; // no of lelemnt from arr1 in leftpart
            
            // Now we will fill the leftpart
            // we now know that mid is the number of elemt present in pargt1 from arr1
            // we can get number of element present in part1 from arr2 as k-mid;
            int x1 = (mid>0)?arr1[mid-1]:-1e9;
            int y1 = ((k-mid)>0 )?arr2[k-mid-1]:-1e9;
            
            // Now we will fill the rightpart
            int x2 = (mid<x)?arr1[mid]:1e9;
            int y2 = (k-mid<y)?arr2[k-mid]:1e9;
            
            if(x1<=y2 && y1<=x2){
                return max(x1,y1);
            }
            
            if(x1>y2){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends