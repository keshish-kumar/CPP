class Solution {
public:
    int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<long long int> arr(n,1);
        while(k--){
            for(int i=1;i<n;i++){
                arr[i] = (arr[i]+arr[i-1])%mod;
            }
        }
        return arr[n-1];
    }
};