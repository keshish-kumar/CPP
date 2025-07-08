class Solution {
  public:
  void merge(vector<int>& arr, int l, int mid, int r){
      vector<int> temp;
      // left vector is l to mid and right vector is mid+1 to r
      int i = l,j=mid+1;
      while(i<=mid && j<=r){
          if(arr[i]<arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          else{
              temp.push_back(arr[j]);
              j++;
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
      
      for(int i=l;i<=r;i++){
          arr[i] = temp[i-l];
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