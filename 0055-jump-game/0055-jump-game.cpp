class Solution {
public:
    bool solve(vector<int>& nums, int index){
        if(index>=nums.size()-1) return true;
        
        for(int i=nums[index];i>0;i--){
            if(solve(nums,index+i)) return true;
        }
        
        return false;
    }
    
    bool canJump(vector<int>& nums) {
       // return solve(nums,0);
       int maxi =0;
       for(int i=0;i<nums.size();i++){
        if(i>maxi) return false;
        maxi = max(maxi,i+nums[i]);

       }
       return true;
    }
};