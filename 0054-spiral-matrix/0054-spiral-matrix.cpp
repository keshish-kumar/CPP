class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int rowup = 0,rowdown = r-1, colleft = 0, colright = c-1;

        while(rowup<=rowdown && colleft<=colright){
            
            if(colleft<=colright){
            // prints the upper row;
            for(int i=colleft;i<=colright;i++){
                ans.push_back(matrix[rowup][i]);
            }
            // reduce the boundary of upper row
            rowup++;
            }

            if(rowup<=rowdown){
            // print the colright
            for(int i=rowup;i<=rowdown;i++){
                ans.push_back(matrix[i][colright]);
            }
            // reduce the colright
            colright--;
            }
            
            if(rowup<=rowdown){
            
            // print the downrow
            for(int i=colright;i>=colleft;i--){
                ans.push_back(matrix[rowdown][i]);
            }

            // reduce the downrow
            rowdown--;
            }
           
           if(colright>=colleft) {
            
            // print the leftcol
            for(int i=rowdown;i>=rowup;i--){
                ans.push_back(matrix[i][colleft]);
            }

            // reduce colleft
            colleft++;
           }

        }

        return ans;
    }
};