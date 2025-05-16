class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        left.push_back(height[0]);
        int maxi = height[0];
        for(int i=1;i<height.size();i++){
            int n = max(maxi,height[i]);
            left.push_back(n);
            maxi = max(maxi,height[i]);
        }

        vector<int> right;
        right.push_back(height[height.size()-1]);
        maxi = height[height.size()-1];
        for(int i = height.size()-2;i>=0;i--){
            int n  = max(maxi,height[i]);
            right.push_back(n);
            maxi = max(maxi,height[i]);
        }
        reverse(right.begin(),right.end());
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans += min(left[i],right[i])-height[i];
        }
        return ans;

    }
};