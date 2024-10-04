class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> count(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2!=0){
                // odd case 
                count[i] = count[i/2]+1;
            }
            else
                count[i] = count[i/2];
        }
        return count;
    }
};