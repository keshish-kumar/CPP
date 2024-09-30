class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         // first reverse 0 to k-1;
         // than reverse k to nums.size();
         // than reverse 0 to nums.size();
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
         reverse(nums.begin()+k, nums.end());
         reverse(nums.begin(),nums.begin()+k);
         

        //  k=k%nums.size();
        // reverse(nums.begin(),nums.end());
        //  reverse(nums.begin(),nums.begin()+k);
        // reverse(nums.begin()+k,nums.end());

    }
};