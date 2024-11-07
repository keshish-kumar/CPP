class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
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
       int sum=0;
       int ans =0;
    mp[0]=1;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];

        if(mp.find(sum-k)!=mp.end()){
            ans+=mp[sum-k];
        }
       
        mp[sum]++;
    }
    return ans;
    }
};