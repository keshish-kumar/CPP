class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans = 0;
        int count =0;
        int t = k;
        while(j<nums.size()){
            if(nums[j]==1 || t--) count++;
            else {
                while(nums[i]!=0){
                    i++;
                    count--;
                }
                i++;
                t=0;
                
            }
            ans = max(ans,count);
            j++;
        }
        return ans;
    }
};