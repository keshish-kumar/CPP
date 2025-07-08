class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int i=1;
        while(i<arr.size()){
            int j = i-1;
            int temp = i;
            while(j>=0 && arr[temp]<arr[j]){
                
                    swap(arr[temp],arr[j]);
                    temp--;
                    j--;
                
            }
            i++;
        }
    }
};