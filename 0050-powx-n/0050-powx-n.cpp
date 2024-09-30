class Solution {
public:
    double myPow(double x, int nn) {
        double answer  = 1;
        long long n = nn;
        if(n<0) n=-1*n;
        int p = n;
        while(n>0){
            if(n%2==0){
                x = x*x;
                n = n/2;
            }
            else{
                answer = answer * x;
                n = n-1;
            }
        }
        if(nn<0) return 1/answer;
        return answer;
    }
};