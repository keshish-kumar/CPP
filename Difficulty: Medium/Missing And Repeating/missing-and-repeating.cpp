//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // fist we have to take sum of numbers of elemnt which will have repeating number
        int n = arr.size();
        long long n1 = 0;
        
        for(int i=0;i<n;i++){
            n1 += arr[i]-(i+1);
        }
        
        
        // Now we have to get sum of squares of the numbers.
        long long n2=0;
        for(int i=0;i<n;i++){
            n2 += pow(arr[i],2)-pow((i+1),2);
        }
        
        n2= n2/n1;
        //cout<<n1<<" "<<n2<<endl;
        // x1-y1=n1 && x2+y2=n2;
        long long x1 = (n1+n2)/2; // repeating number 
        long long y1 = n2-x1; // missing number
        
        return {x1,y1};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends