class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        // min heap as default is max heap;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        while(k--){
            ans = pq.top();
            pq.pop();
        }

      return ans;
    }
};