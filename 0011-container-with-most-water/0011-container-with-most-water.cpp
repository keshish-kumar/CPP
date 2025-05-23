class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left<right){
            int area = (right-left)*(min(height[left],height[right]));
            if(height[left]>height[right]) right--;
            else left++;
            ans = max(ans,area);
        }
        return ans;
    }
};