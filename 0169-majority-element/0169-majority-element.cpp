class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int,int> p; // element and its count
        p = {nums[0],1};

        for(int i=0;i<nums.size();i++){
            if(p.first==nums[i]){
                p.second++;
            }
            else{
                p.second--;
            }
            if(p.second==0){
                p = {nums[i],1};
            }
        }
        return p.first;
    }
};