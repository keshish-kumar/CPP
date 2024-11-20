class Solution {
public:
        
        bool static comp(vector<int> a, vector<int> b){
         return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans =0;
        sort(intervals.begin(),intervals.end(),comp);
        int i=0,j=1;
        while(j<intervals.size()){
            if(intervals[i][1]>intervals[j][0]){
                j++;
                ans++;
            }
            else{
                i = j;j++;
            }
        }
        return ans;
    }
};