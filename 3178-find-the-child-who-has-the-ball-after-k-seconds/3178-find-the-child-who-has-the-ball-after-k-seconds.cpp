class Solution {
public:
    int numberOfChild(int n, int k) {
        
        int i=0,j=n-1;
        bool flag = true;
        while(k>0){
            if(i<n-1 && flag==true){
             
                i++;
            }
            else if(i>0 && flag == false){
              
                i--;
            }
            if(i==0){
                flag = true;
            }
            if(i==n-1){
                flag = false;
            }
            k--;
        }
        return i;
        
    }
};