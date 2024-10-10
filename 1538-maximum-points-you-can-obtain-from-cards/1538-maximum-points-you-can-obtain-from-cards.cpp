class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // approach-1 find minimum subarray of size n-k and substract it from total sum to get that value
        // approach-2 callulate sum till k from left and than start from rihgt and subtract it from left add from right

        // calculating subarray with minimum sum
        int n = cardPoints.size();
        int sum = 0;
        int i=0,j=0;
        int ans =INT_MAX;
        while(j<n){
            sum+=cardPoints[j];
            if((j-i+1)==(n-k)){
                ans = min(ans,sum);
                sum-=cardPoints[i];
                i++;
            }
            j++;
        }
        int t = accumulate(cardPoints.begin(),cardPoints.end(),0);
        return n==k?t:t-ans;
    }
};