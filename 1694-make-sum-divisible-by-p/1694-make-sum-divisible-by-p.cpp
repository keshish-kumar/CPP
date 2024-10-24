class Solution {
public:
    
    int minSubarray(vector<int>& nums, int p) {
        map<int,int> mp;//stores mod value and its index;
        mp[0]=-1;
        int ans =INT_MAX;
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum%p==0) return 0;
        long long target = sum%p;
        long long currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            long long n = (currsum-target+p)%p;
            if(mp.find(n)!=mp.end()){
                ans = min(ans,i-mp[n]);
            }

            mp[currsum%p]=i;
        }

        return ans==nums.size()?-1:ans;
    }
};