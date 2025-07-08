class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        for(int i=0;i<arr.size();i++){
            bool swapper= false;
            for(int i=1;i<arr.size();i++){
                if(arr[i]<arr[i-1]){
                    swap(arr[i],arr[i-1]);
                    swapper = true;
                }
            }
            if(!swapper) return;
        }
    }
};