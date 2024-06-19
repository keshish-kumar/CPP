class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // here we are taking lpong lpong beacuse int might exceede its capacity
        if(nn<0) nn = -1*nn;  // this is to handle any neagtive numbners 
        double ans = 1; // when 2^10 is converted to power 5 (10/2) than ans is used to store that odd value 4*4^4                          // which is 4*ans; 
        while(nn>0){
            
            if(nn%2==1){
                ans = ans*x;
                nn = nn-1;
            }
            else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n<0) ans = 1/ans;    // use to hadle if any negative power there than divide the answer.
        
        return ans;
    }
};