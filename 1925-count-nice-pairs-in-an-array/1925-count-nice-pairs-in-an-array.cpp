class Solution {
public:
    int reverse(int n){
        int ans =0;
        while(n>0){
            int i = n%10;
            ans   =  ans*10 + i;
            n=n/10;
           
        }
        return ans;
    }
    long long  combinationof(int n){

        long long int   ans = ((1LL*n*(n-1))/2);
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        map<long long int,long long int> mp;
        for(int i=0;i<nums.size();i++){
            int n = nums[i]-reverse(nums[i]);
            
            mp[n]++;
           cout<<mp[nums[i]]<<endl;
        }
       
        // Now we will calculate the answer for this using combination formual
       long long int   answer =0;
        for(auto it:mp){
            if(it.second > 1)
                answer = (answer+combinationof(it.second))%(1000000007);
            
        }
    return (int)answer;
    }
};