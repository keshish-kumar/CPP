class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // first we have to find the element which statiosfys arr[i-1]<arr[i] from right nindex 
        // than after getting the index (i-1) we have to ssap with element on right side of it which is just greater that that.
        // than we have to revsre from i to end;
        // else if everything is in descedning order than we ahve to ervsre it
        for(int i=nums.size()-1;i>0;i--){
            // wehave to look for the cse arr[i-1]<arr[i]
            if(nums[i-1]<nums[i]){
                
                // Now we have to search for the element which is just graeter than arr[i-1]
                int k = 0;
                for(int j=nums.size()-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                       
                        k=j;
                        break;
                    }
                }
                swap(nums[i-1],nums[k]);
                reverse(nums.begin()+i,nums.end());
                return ;

            }
        }
        reverse(nums.begin(),nums.end());

        
    }
};