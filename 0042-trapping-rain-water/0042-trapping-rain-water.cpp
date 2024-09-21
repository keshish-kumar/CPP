class Solution {
public:
    vector<int> left(vector<int>& height){
        int maxi = height[0];
        vector<int> v;
        v.push_back(height[0]);
        for(int i=1;i<height.size();i++){
            maxi = max(maxi,height[i]);
            v.push_back(maxi);
        }
        return v;
    }

    vector<int> right(vector<int>& height){
        int maxi = height[height.size()-1];
        vector<int> v;
        v.push_back(maxi);
        for(int i=height.size()-2;i>=0;i--){
            maxi = max(maxi,height[i]);
            v.push_back(maxi);
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int trap(vector<int>& height) {
        vector<int> leftmax = left(height);
        vector<int> rightmax = right(height);
        int ans =0;
        
        for(int i=0;i<height.size();i++){
            ans += (min(leftmax[i],rightmax[i])-height[i]);
        }
        return ans;

    }
};