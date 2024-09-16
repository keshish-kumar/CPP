class Solution {
public:
    int maxArea(vector<int>& height) {
        // first brute force approcg goes in n^2 time 
        // for each node check other node and calculate the area.

        // second approach is using two pointer approach

        int i=0,j=height.size()-1;
        int area = 0;
        while(i<j){
            int temp_height = min(height[i],height[j]);
            int temp_area = temp_height*(j-i); 
            area = max(area,temp_area);
            if(height[i]>height[j]) j--;
            else i++;
        }

        return area;

    }
};