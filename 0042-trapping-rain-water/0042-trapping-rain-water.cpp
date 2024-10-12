class Solution {
public:
    int trap(vector<int>& height) {
        // minimum of left max and rightmax
        vector<int> leftmax(height.size(),0);
        int maxi = height[0];
        for(int i=0;i<height.size();i++){
            maxi = max(height[i],maxi);
            leftmax[i] = maxi;
        }

        vector<int> rightmax(height.size(),0);
        maxi = height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            rightmax[i] = maxi;
        }
       

        int ans =0;
        for(int i=0;i<height.size();i++){
            ans += min(rightmax[i],leftmax[i])-height[i];
        }

        return ans;
    }
};