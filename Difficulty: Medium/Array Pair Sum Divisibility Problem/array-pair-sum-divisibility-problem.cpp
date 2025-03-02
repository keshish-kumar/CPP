//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool canPair(vector<int> &arr, int k) {
        // Code here.
        if(arr.size()%2 != 0) return false;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            int r1 = arr[i]%k;
            int r2 = k-r1;
            if(r1 == 0) 
                r2=0;
            
            if(mp.find(r2)!=mp.end()){
                
                mp[r2]--;
                
                if(mp[r2]==0)
                     mp.erase(r2);
            }
            else{
                mp[r1]++;
            }
        }
       
      return mp.empty()?true:false;
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution obj;
        bool ans = obj.canPair(arr, k);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends