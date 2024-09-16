class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size()),rmax(height.size());
        int maxi = INT_MIN;
        for(int i=0;i<height.size();i++){
            maxi = max(maxi,height[i]);
            lmax[i] = maxi;
        }
         maxi = INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            rmax[i] = maxi;
        }

        // Now that we got right max and left max we will traverse each node and check if it can trap water or not

        int ans =0;
        for(int i=0;i<height.size();i++){
            int temp = min(lmax[i],rmax[i]);
            ans += temp-height[i];
        }

        return ans;
    }
};