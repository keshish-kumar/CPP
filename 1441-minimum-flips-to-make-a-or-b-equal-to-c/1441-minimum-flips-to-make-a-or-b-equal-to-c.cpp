class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        int i=0;
        while(a>0 || b>0 || c>0){
            // a|b == c
            if((c&1)!=0){
                if(a&1 != 0 || b&1 != 0) flip+=0;
                else{
                    flip++;
                }
            }
            else{
                if(a&1 !=0 && b&1 != 0) flip+=2;
                else if(a&1 !=0 || b&1 != 0){
                    flip++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return flip;

    }
};