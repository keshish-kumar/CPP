class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of useful elements in a decreasing order
        vector<int> ans;

        int i=0,j=0;
        while(j<nums.size()){
            while(!dq.empty() && dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if((j-i+1)==k){
                ans.push_back(dq.front());
                if(nums[i]==dq.front()) dq.pop_front();
                i++;
            }
            j++;
        }
        
        return ans;
    }
};