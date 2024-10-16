//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int m) {
        // code here
        map<int , int> mp;
        int ans =0;
        int curr=0;
        mp[0]=1;
        for(int i=0;i<arr.size();i++){
            curr ^= arr[i];
            if(mp.find((m^curr))!=mp.end()){
                ans+=mp[curr^m];
            }
            mp[curr]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int m;
        cin >> m;
        cin.ignore(); // Ignore the newline after m

        Solution obj;
        cout << obj.subarrayXor(arr, m) << endl;
    }
    return 0;
}
// } Driver Code Ends