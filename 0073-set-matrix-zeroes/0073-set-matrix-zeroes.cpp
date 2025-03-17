class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        set<pair<int,int>> st;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    st.insert({i,j});
                }
            }
        }

        // we need to mark all thqat rows and col to 0 givrn in set st;

        for(auto it:st){
            int row = it.first;
            int col = it.second;
            for(int i=0;i<matrix[0].size();i++){
                matrix[row][i] = 0;
            }
            for(int i=0;i<matrix.size();i++){
                matrix[i][col] = 0;
            }
        }

    }
};