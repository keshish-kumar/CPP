//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        // The minimum. dostance any two of them is maximum possible
        sort(stalls.begin(),stalls.end());
        int low = 0,high = accumulate(stalls.begin(),stalls.end(),0);
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            int count =1,sum=0;
            int i=0,j=1;
            while(j<stalls.size()){
                if(abs(stalls[i]-stalls[j])>=mid){
                    count++;
                    i=j;
                    j++;
                }
                else{
                    j++;
                }
            }
            if(count>= k){
                ans = mid;
                low = mid+1;
            }
            else{
                
                high = mid-1;
            }
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

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends