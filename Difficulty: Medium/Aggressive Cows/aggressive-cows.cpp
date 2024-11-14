//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(vector<int>& stalls, int d, int k){
        int count=1;
        int i=1;
        int l=stalls[0];
        while(i<stalls.size()){
            if(stalls[i]-l>=d){
                count++;
                l = stalls[i];
            }
            i++;
        }
        if(count>=k) return true;
        else return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low = 1,high = *max_element(stalls.begin(),stalls.end());
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(solve(stalls,mid,k)){
                ans = max(ans,mid);
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