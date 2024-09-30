class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]==val){
                while(i<=j && nums[j]==val){
                    j--;
                }
                if(i>j) break;
                swap(nums[i],nums[j]);
                j--;
            }
            i++;
        }
        int ans =0 ;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) ans++;
        }
        return ans;
    }
};