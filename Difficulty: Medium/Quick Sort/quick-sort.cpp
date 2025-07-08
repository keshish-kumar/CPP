class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high){
            int pivot = partition(arr,low,high);
            
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot = high;
        int pi = low;
        int i = low;
        while(i<high){
            if(arr[i] < arr[pivot]){
                swap(arr[i],arr[pi]);
                pi++;
            }
            i++;
        }
        swap(arr[pi],arr[pivot]);
        return pi;
    }
};