class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int i=0;
        // int j=0;
        // int sum=0;
        // int ans =0;
        // int count=0;
        // while(j<nums.size()){
        //     sum += nums[j];
        //     while(i<j && (nums[i]==0 || sum>goal)){
        //         if(nums[i]==0) count++;
        //         else count=0;
        //         sum = sum-nums[i];
        //         i++;
        //     }
        //     if(sum==goal){
        //         ans += 1+count;
        //     }
        //     j++;
        // }
        // return ans;

        map<int,int> mp;
        int ans =0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == goal) ans++;
            if(mp.find(sum-goal)!=mp.end()){
                ans = ans+mp[sum-goal];
            }
            mp[sum]++;
        }
    return ans;
    }
};