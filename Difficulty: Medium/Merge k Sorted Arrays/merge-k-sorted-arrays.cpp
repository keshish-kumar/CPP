class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int> ans;
        for(int t=0;t<K;t++){
            int i =0;
            int j =0;
            vector<int> temp;
            while(i<ans.size() && j<K){
                if(ans[i]<arr[t][j]){
                    temp.push_back(ans[i]);
                    i++;
                }
                else{
                    temp.push_back(arr[t][j]);
                    j++;
                }
            }
            while(i<ans.size()){
                temp.push_back(ans[i]);
                i++;
            }
            while(j<K){
                temp.push_back(arr[t][j]);
                j++;
            }
            ans=temp;
        }
        return ans;
    }
};