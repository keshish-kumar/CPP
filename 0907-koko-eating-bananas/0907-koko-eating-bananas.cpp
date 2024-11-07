class Solution {
public:
    bool fun(int m,vector<int>& piles, int h){
        int count = 0;
        for(int i=0;i<piles.size();i++){
             count += (piles[i] + m - 1) / m;

            if(count > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<piles.size();i++){
            high = max(high,piles[i]);
        }

        while(low<=high){
            int mid = low + (high-low)/2;

            if(fun(mid,piles,h))
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};