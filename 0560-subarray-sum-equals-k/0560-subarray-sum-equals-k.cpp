class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int ans =0;
        // int sum =0;
        // int j=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //      while(j<i && sum>k){
        //         sum=sum-nums[j];
        //         j++;
        //     }
        //     if(sum==k){
        //         ans++;
        //     }
        // }
        // return ans; // this will work only for positive numbers.'

        map<int,int> mp;
        int count=0;
        int presum=0;
        mp[0] = 1; // this is very imporatnat to handle the zero case. try test case [3,-3,1,1,1]
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            if(mp.find(presum-k)!=mp.end()){
                count += mp[presum-k];
            }
            mp[presum]++;
        }
        return count;
    }
};