class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // we will directly use two pointer here as elements are soted
        int i=0,j=numbers.size()-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum==target){
                return {i+1,j+1};
            }
            if(sum>target){
                j--;
            }
            else i++;
        }
        return {-1,-1};
    }
};