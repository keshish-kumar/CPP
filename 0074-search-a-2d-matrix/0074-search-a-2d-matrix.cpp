class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // first we needd to find out the row to whcioh that target might belong
        int left = 0,right = matrix.size()-1;
        int row = -1;
        int n = matrix[0].size();
        while(left<=right){
            int mid = (left+right)/2;
            if(matrix[mid][n-1] == target) return true;
           
            if(matrix[mid][n-1] > target){
                row = mid;
                right = mid-1;
            }
            else{
                
                left = mid+1;
            }
        }
        cout<<row<<endl;
        // nOw we got the than we will search in that row
        left = 0;right = matrix[0].size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(matrix[row][mid]==target) return true;

            if(matrix[row][mid]>target) right = mid-1;
            else left = mid+1;
        }

        return false;
    }
};