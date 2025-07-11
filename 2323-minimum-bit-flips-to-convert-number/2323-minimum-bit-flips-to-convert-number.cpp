class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans =0;
        while(start || goal){
            if((start&1)^(goal&1)) ans++;
            start= start>>1;
            goal= goal>>1;
        }
        return ans;
    }
};