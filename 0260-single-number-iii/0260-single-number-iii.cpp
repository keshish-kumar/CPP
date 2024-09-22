class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // we will apply xor operation for this
        int n1=0;
        for(int i=0;i<nums.size();i++){
            n1 = n1^nums[i];
        }
        // 3^5 will be in xor which will be 4
        // Now we have to find at what bit 3 and 5 will differ
        int bitno = 0;
        int temp =n1;
        while((n1&1)==0){
            bitno++;
            n1>>=1;
        }
        // we will get at what position the bit  will differ

        // now we will seperate all that numbers wchich differs at that bit position
        int n2=0;n1=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<bitno))!=0){
                n1 ^= nums[i];
            }
            else n2 ^= nums[i];
            
        }

        return {n1,n2};

    }
};