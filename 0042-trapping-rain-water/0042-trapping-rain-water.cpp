class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        int maxi = height[0];
        for(int i=0;i<height.size();i++){
            maxi = max(maxi,height[i]);
            left.push_back(maxi);
        }
        vector<int> right;
        maxi = height[height.size()-1];
        for(int i=height.size()-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            right.push_back(maxi);
        }
        reverse(right.begin(),right.end());

        int ans =0;
        for(int i=0;i<height.size();i++){
            ans += min(left[i],right[i])-height[i];
        }
        return ans;
    }
};