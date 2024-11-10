class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> p;
        p.first=nums[0];
        p.second=1;
        for(int i=1;i<nums.size();i++){
           
            if(p.first==nums[i]){
                p.second++;
            }
            else{
                p.second--;
            }
            if(p.second==0){
                p.first=nums[i];
                p.second=1;
            }
        }
        return p.first;
    }
};