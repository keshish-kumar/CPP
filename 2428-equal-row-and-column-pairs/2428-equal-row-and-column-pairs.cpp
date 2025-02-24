class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // lets store all the row values as a single vector
        map<vector<int>,int> st;
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid[0].size();j++)
                temp.push_back(grid[i][j]);
            st[temp]++;
        }
        // for(auto it:st){
        //     for(int i=0;i<it.size();i++) cout<<it[i]<<" ";
        //     cout<<endl;
        // }

        // Now map to the every colm to set of rows values
        int ans = 0;
        for(int i=0;i<grid[0].size();i++){
            vector<int> temp;
            for(int j=0;j<grid.size();j++)
                temp.push_back(grid[j][i]);
            if(st.find(temp)!=st.end()) ans+= st[temp];
        }
        return ans;
    }
};