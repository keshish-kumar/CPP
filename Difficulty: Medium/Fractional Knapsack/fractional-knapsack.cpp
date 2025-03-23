//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        // we will take vector of pair which conatin both val/weight
        vector<pair<double,int>> v;
        for(int i=0;i<val.size();i++){
            v.push_back({(double)val[i]/wt[i] , i});
        }
        sort(v.rbegin(),v.rend());
        double ans=0;
        for(int i=0;i<v.size();i++){
            int idx = v[i].second;
            int weight = wt[idx];
            if(capacity>=weight){
                capacity -= weight;
                ans += val[idx];
            }
            else{
                ans += (double)v[i].first*capacity;
                break;
            }
            
           // cout<<capacity<<endl;
            
           // if(capacity == 0) break;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends