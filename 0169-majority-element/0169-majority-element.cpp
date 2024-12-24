class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elm = nums[0];

        int count =1;
        for(int i=1;i<nums.size();i++){
            if(count==0) {count=1;elm=nums[i];}
            else if(nums[i]!=elm) count--;
            else count++;
        }
    return elm;
    }
};