class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first we have to search for row;
        int low=0,high = matrix.size()-1;
        int row = 0;
        while(low<=high){
            int mid = (low+high)/2;
            //row = mid;
            if(matrix[mid][matrix[0].size()-1]==target) return true;
            if(matrix[mid][matrix[0].size()-1]<target) low = mid+1;
            else{
            row = mid;
            high=mid-1;
            
            } 
        }

        // we will take high as the row
        
       
        cout<<row<<endl;
        low =0; high = matrix[0].size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[row][mid]==target) return true;
            if(matrix[row][mid]<target) low=mid+1;
            else high=mid-1;
        }

        return false;

    }
};