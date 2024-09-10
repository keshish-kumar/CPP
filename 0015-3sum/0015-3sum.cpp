class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int target = -1*nums[i];
            unordered_set<int> mp;
            int left = i+1,right=nums.size()-1;
            while(left<right){
                if((nums[left]+nums[right])==target){
                    ans.insert({-1*target,nums[left],nums[right]});
                    left++;right--;
                }
                else if((nums[left]+nums[right]>target)){
                    right--;
                }
                else
                    left++;
            }
        }
        
        vector<vector<int>> a;
        for(auto it:ans)
            a.push_back(it);
        return a;
    }
};