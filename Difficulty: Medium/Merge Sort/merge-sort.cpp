//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void merge(vector<int>& arr, int l, int mid, int r){
      vector<int> temp;
      int start=l,end=r;
      int i=0;
      int k = mid+1;
      while(l<=mid && k<=r){
          if(arr[l]<arr[k]){
              temp.push_back(arr[l++]);
          }
          else{
              temp.push_back(arr[k++]);
          }
      }
      while(l<=mid){
          temp.push_back(arr[l++]);
      }
      while(k<=r){
          temp.push_back(arr[k++]);
      }
      
      for(int t=start;t<=end;t++){
          arr[t]=temp[t-start];
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        // first we need to divided in suck a way that only single element remains at last
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends