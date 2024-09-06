class Solution {
    public int majorityElement(int[] nums) {
        
        int count=1;
        int a = nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=a){
                count--;
            }
            else{
                count++;
            }
            if(count==0){
                a=nums[i];
                count=1;
            }
        }
        return a;
    }
}