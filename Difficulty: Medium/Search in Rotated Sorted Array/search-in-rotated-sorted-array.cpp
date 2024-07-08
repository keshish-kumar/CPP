//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int subarray(vector<int>&arr, int low , int high,int target){
      
      while(low<=high){
          int mid = low + (high-low)/2;
          if(arr[mid]==target) return mid;
          else if(arr[mid]<target){
              low = mid+1;
          }
          else
          high = mid-1;
      }
      return -1;
      
  }
  
  int pivot(vector<int>&arr,int low, int high){
      
      while(low<high){
          int mid = low + (high-low)/2;
          
          if(arr[mid] > arr[high]){
              low = mid+1;
          }
          else
            high = mid;
      }
      
      return low;
  }
    int search(vector<int>& arr, int key) {
        // complete the function here
       int low = 0;
       int high = arr.size()-1;
       
           int p =  pivot(arr,0,arr.size()-1);
           int left = subarray(arr,0,p-1,key);
           int right =subarray(arr,p,arr.size()-1,key);
           
           if(left != -1) return left;
           else if (right != -1) return right;
           else
                return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends