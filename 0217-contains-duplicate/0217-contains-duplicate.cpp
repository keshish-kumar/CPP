class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> st;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            st[nums[i]]++;
            if(st[nums[i]]>=2) return true;
        }
        return flag;
    }
};