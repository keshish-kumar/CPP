class Solution {
public:
    // static bool compr(vector<int>& a, vector<int>& b){
    //     return a[0]<b[0];
    // }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

            vector<vector<int>> ans;

            // first we have to which all elenments comes before the interval

            int i=0;
            while(i<intervals.size() && intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
                i++;
            }

            // after fidning out where it is object
            
            while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
                i++;
            }

            ans.push_back(newInterval);

            // Now push the rest of the lement in it


            while(i<intervals.size()){
                ans.push_back(intervals[i]);
                i++;
            }
        return ans;
    }
};