class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        int maxi = height[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            left[i] = maxi;
            
        }

        vector<int> right(n,0);
        maxi = height[n-1];
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            right[i] = maxi;
        }

        int ans =0;
        for(int i=0;i<n;i++){
            ans += min(left[i],right[i])-height[i];
        }
        return ans;
    }
};