class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        

        int num1=INT_MAX,num2=INT_MAX,num3=INT_MAX;

        for(int i=0;i<arr.size();i++){
            num3=arr[i];
            if(num3<=num1){
                num1=num3;

                //cout<<"num1="<<num1<<endl;
            }
            else if(num3<=num2){
                num2=num3;
               // cout<<"num2="<<num2<<endl;
            }
            else {
                return true;
            }
        }


        return false;
    }
};