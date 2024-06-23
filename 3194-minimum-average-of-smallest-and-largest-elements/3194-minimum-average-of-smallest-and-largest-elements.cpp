class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        // here w ehave to remove the samllest and maximum element sum /2 and add it to averages and return min             //averages
        sort(nums.begin(),nums.end());
        double ans = 1e9;
        for(int i=0,j=nums.size()-1;i<nums.size()/2;i++,j--){
            double temp = static_cast<double>((nums[i]+nums[j])/2.0);
            if(ans>temp)
                ans = temp;
        }
        
        return ans;
        
    }
};