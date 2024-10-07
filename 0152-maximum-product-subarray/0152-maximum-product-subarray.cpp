class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        // we will do from both left and right to calcujlate the array

        int count =1;
        int ans = nums[0];
        for(int i=0;i<nums.size();i++){
            count *= nums[i];
             ans = max(ans,count);
            if(count ==0 ) count =1;
           
        }

        // check from right side

        count =1;
        for(int i=nums.size()-1;i>=0;i--){
            count *=nums[i];
             ans = max(ans,count);
            if(count ==0 ) count =1;
           
        }
        return ans;
    }
};