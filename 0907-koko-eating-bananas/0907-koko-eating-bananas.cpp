class Solution {
public:
    long long solve(vector<int>& piles, int t){

        long long  ans = 0;
        for(int i=0;i<piles.size();i++){
            ans += ceil((double)piles[i]/t);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;

            if(solve(piles,mid) <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};