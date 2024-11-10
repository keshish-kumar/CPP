class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        set<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            
                int l = i+1,r=nums.size()-1;
                
                while(l<r){

                    if(nums[l]+nums[r] == -nums[i]){
                        ans.insert({nums[i],nums[l],nums[r]});
                        l++;r--;
                    }
                    else if(nums[l]+nums[r] < -nums[i]){
                        l++;
                    }
                    else{
                        r--;
                    }
                }
        }
        vector<vector<int>> v;
        for(vector<int> it: ans)
            v.push_back(it);
        return v;
    }
};