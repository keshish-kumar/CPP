class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> temp(matrix.size(),vector<int>(matrix[0].size()));
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                temp[i][j] = matrix[i][j]-'0';
                //ans = max(ans,temp[i][j]);
            }
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if((i-1>=0) && (j-1)>=0 && temp[i][j] ==1) {
                    temp[i][j] = temp[i][j]+ min({temp[i-1][j],temp[i][j-1],temp[i-1][j-1]});
                }
                ans = max(ans,temp[i][j]);
            }
        }
        return ans*ans;
    }
};