//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(vector<int>& arr, int i, int sum){
      if(sum==0) return true;
      if(sum<0 || i>=arr.size()) return false;
      return solve(arr,i+1,sum-arr[i]) || solve(arr,i+1,sum);
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return solve(arr,0,sum);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends