class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first we have to fidn transpose of the matrix;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        // now we habve to swap the col 
        for(int i=0;i<matrix.size();i++){
            int k=0,j=matrix[i].size()-1;
            while(k<j){
                swap(matrix[i][k],matrix[i][j]);
                k++;j--;
            }

        }
    }
};