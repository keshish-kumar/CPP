class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        
        // first we will tryn to merge the intervals;
        vector<vector<int>> v; 
        
        if(interval.size()==0) {v.push_back(newInterval);return v;}
        int i=0,j=0;
        
       bool flag =true;
        while(j<interval.size()){
            
            if(flag && newInterval[1]<interval[j][0]){
                v.push_back(newInterval);
                flag=false;
            }
             if(flag && newInterval[0]<=interval[j][1]){
                int x=j;
                
                int maxi = max(newInterval[1],interval[x][1]);
                x++;
                while(x<interval.size() && interval[x][0]<=newInterval[1]){
                    maxi = max(interval[x][1],newInterval[1]);
                    x++;
                }
                
                v.push_back({min(interval[j][0],newInterval[0]),maxi});
                j=x;
                flag=false;
            }
            
            else{
                v.push_back(interval[j]);
                j++;
                
            }
            
        }
        
        if(flag) v.push_back(newInterval);
        return v;
    }
};