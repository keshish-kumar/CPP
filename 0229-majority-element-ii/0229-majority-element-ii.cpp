class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int target = nums.size()/3;
        int count1=0;
        int a=NULL;
        int count2=0;
        int b=NULL;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i]){
                count1++;
            }
            else if(b==nums[i]){
                count2++;
            }
            else if(count1==0){
                    count1=1;
                    a=nums[i];
            }
            else if(count2==0){
                count2=1;
                b = nums[i];
            }
            else{
                count1--;
                count2--;
            }
            
            
        }
       
        int n1 = 0;
        int n2 = 0;
        for(int i=0;i<nums.size();i++){
            if(a==nums[i]) n1++;
            else if(b==nums[i]) n2++;
        }
        if(n1>target) ans.push_back(a);
        if(n2>target) ans.push_back(b);
       // cout<<"n1="<<n1<<" n2="<<n2<<endl;
        return ans;
    }
};