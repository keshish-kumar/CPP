class Solution {
public:
    int mySqrt(int x) {
        // use binary search to get the value;
        if(x==1) return 1;
        long long low = 1,high = x/2;

        while(low<=high){
            long long mid = (low+high)/2;
            if((mid*mid)==x) return mid;
            if((mid*mid)>x){

                high = mid-1;
            }
            else
                low = mid+1;
        }
        return high;
    }
};