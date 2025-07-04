class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            int t = i;
            int temp = 0;
            while(t>0){
                if((t &1)!=0) temp++;
                t = t>>1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};