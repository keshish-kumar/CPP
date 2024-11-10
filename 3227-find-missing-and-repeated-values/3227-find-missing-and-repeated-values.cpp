class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                arr.push_back(grid[i][j]);
        }

        int b=0;
       
        for(int i=0;i<arr.size();i++){
            b ^=arr[i]^(i+1);
            
        }
        
        // Now we have to check to what bit x^y=b differen in b
        int k=0;
        while(1){
            if((b&(1<<k)) != 0){
                break;
            }
            k++;
        }
        
        // Now wehave to sperate the lement 
        int n1=0,n2=0;
        for(int i=0;i<arr.size();i++){
            if((arr[i]&(1<<k)) !=0){
                n1 ^= arr[i];
            }
            else{
                n2^=arr[i];
            }
            
            if(((i+1)&(1<<k))!=0){
                n1 ^= (i+1);
            }
            else{
                n2 ^= (i+1);
            }
        }
        
        // lets find missing value
        
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==n1) count++;
        }
        
        if(count==2) return {n1,n2};
        else return {n2,n1};
        
    }
};