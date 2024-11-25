//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
         int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            int pages = 0; int count=1;
            for(int i=0;i<arr.size();i++){
                pages += arr[i];
                if(pages>mid){
                    pages = arr[i];
                    count++;
                }
            }
            if(count<=k){
                ans = mid;
                high = mid-1;
                
            }
            else low =  mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends