//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void merge(vector<int>& arr, int l,int mid, int r){
      int i=l,j=mid+1;
      vector<int> temp;
      while(i<=mid && j<=r){
          if(arr[i]>arr[j]){
              temp.push_back(arr[j]);
              j++;
          }
          else{
              temp.push_back(arr[i]);
              i++;
          }
      }
      while(i<=mid){
          temp.push_back(arr[i]);
          i++;
      }
      while(j<=r){
          temp.push_back(arr[j]);
          j++;
      }
      // now we have to put this leents in origignal array
      int t=0;
      for(int k=l;k<=r;k++){
          arr[k] = temp[t];
          t++;
      }
  }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
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