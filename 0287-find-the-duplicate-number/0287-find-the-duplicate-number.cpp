class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        // find if cycle is present or not
        while(slow!=fast){
            slow=nums[slow];
            fast = nums[nums[fast]];
        }

        // find the entrance to the ycle
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};