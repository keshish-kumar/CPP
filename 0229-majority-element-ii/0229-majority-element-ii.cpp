class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = NULL;
        int b = NULL;
        int count1=0;
        int count2=0;
        int t = nums.size()/3+1;
        for(int i=0;i<nums.size();i++){
            if (nums[i] == a) {
                count1++;
            } else if (nums[i] == b) {
                count2++;
            } else if (count1 == 0) {
                a = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                b = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==a) c1++;
            else if(nums[i]==b) c2++;
            
        }
        vector<int> ans;
        if(c1>=t) ans.push_back(a);
        if(c2>=t) ans.push_back(b);
        return ans;
    }
};