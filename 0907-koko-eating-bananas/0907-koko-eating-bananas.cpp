class Solution {
public:
    bool solve(vector<int>& piles, int t, int h){
        long long time = 0;
        for(int i=0;i<piles.size();i++){
            time += (piles[i] + t - 1) / t;

        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            bool res = solve(piles,mid,h);
            if(!res){
                
                low= mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};