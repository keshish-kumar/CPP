class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =1;
        int n = digits.size();
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+carry >= 10){
                digits[i]=0;
                carry =1;
            }
            else{
                digits[i]+=1;
                carry =0;
            }
            if(carry==0) return digits;
        }
        if(carry==1){
            digits.push_back(1);
            reverse(digits.begin(),digits.end());
        }
        return digits;
    }
};