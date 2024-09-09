class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0)
                    v.push_back({i,j});
            }
        } 

        for(int i=0;i<v.size();i++){
            int row = v[i].first;
            int col = v[i].second;

            for(int j=0;j<matrix[row].size();j++){
                    matrix[row][j] = 0;
            }

            for(int j=0;j<matrix.size();j++){
                matrix[j][col] = 0;
            }
        }

    }
};