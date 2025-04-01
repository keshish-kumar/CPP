class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0;
        vector<int> countLeft(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                countLeft[i]=countLeft[i-1]+1;  
            }
        }
       vector<int> countRight(n,1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] ){
                countRight[i] = countRight[i+1]+1;
            }
        }
        vector<int> count(n,0);
        for(int i=0;i<n;i++)
           { count[i] = max(countLeft[i],countRight[i]);
               
           }
           
        ans = accumulate(count.begin(),count.end(),0);

        return ans;
    }
};