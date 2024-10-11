class Solution {
public:
    int solve(vector<int>& nums, int k){

        map<int,int> mp;
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            mp[nums[j]]++;
           
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
             if(mp.size()<=k){
                ans += (j-i+1);
            }
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // no of subarrays with (atmost k) - (atmost k-1) will give subarray with k diffeernent integer

        return solve(nums,k)-solve(nums,k-1);
    }
};