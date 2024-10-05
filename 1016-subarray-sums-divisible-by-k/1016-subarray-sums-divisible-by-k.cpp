class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        // as we were string summ and checking for sum-k is present or not
        // simillarly here we will check if sum%k is prestn in this or not

        mp[0] = 1;
        int sum=0;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int n = sum%k;
            if(n<0) n = k+n;
            if(mp.find(n)!=mp.end()){
                ans += mp[n];
            }
            mp[n]++;
        }
        return ans;
    }
};