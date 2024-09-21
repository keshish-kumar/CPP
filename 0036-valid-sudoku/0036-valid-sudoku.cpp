class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // validate col

        // for(int i=0;i<9;i++){ // col fixed
        //     set<char> st;
        //     for(int j=0;j<9;j++){ // rows changing
        //         if(st.find(board[j][i])!=st.end()) return false;
        //         if(board[j][i]>='0' && board[j][i]<='9') st.insert(board[j][i]);
        //     }
        // }
        // cout<<"col checked"<<endl;
        // // validate row

        // for(int i=0;i<9;i++){ // row fixed
        //     set<char> st;
        //     for(int j=0;j<9;j++){ // col changing
        //         if(st.find(board[i][j])!=st.end()) return false;
        //         if(board[i][j]>='0' && board[i][j]<='9') st.insert(board[i][j]);
        //     }
        // }
        // cout<<"row checked"<<endl;
        // // validate. 3*3 boxes

        // for(int i=0;i<9;i=i+3){
        //     for(int j=0;j<9;j=j+3){
        //         set<char> st;
        //         for(int row=i;row<(i+3);row++){
        //             for(int col = j ;col<(j+3);col++){
        //                 if(st.find(board[row][col])!=st.end()) return false;
        //                 if(board[row][col]>='0' && board[row][col]<='9') st.insert(board[row][col]);
        //             }
        //         }
        //     }
        // }
        // cout<<"boxes checked"<<endl;
        // return true;
        set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                // row
                string row = to_string(i)+"row"+board[i][j];
                if(st.find(row)!=st.end()) return false;
                st.insert(row);
                
                string col = to_string(j)+"col"+board[i][j];
                if(st.find(col)!=st.end()) return false;
                st.insert(col);
                
                string box = to_string(i/3)+to_string(j/3)+"box"+board[i][j];
                if(st.find(box)!=st.end()) return false;
                st.insert(box);
                
                }
            }
        }
        return true;
    }
};