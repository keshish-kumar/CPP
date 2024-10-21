class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = lower_bound(arr.begin(),arr.end(),x)-arr.begin()-1;
        cout<<n<<endl;
        int i=n,j=n+1;
       
        while(i>=0 && j<arr.size()){
            if(abs(x-arr[i])<=abs(x-arr[j])){
                ans.push_back(arr[i]);
                k--;
                i--;
            }
            else{
                ans.push_back(arr[j]);
                k--;
                j++;
            }
            if(k==0) break;
        } 
        while(k>0 && i>=0){
            ans.push_back(arr[i]);
            k--;
            i--;
            if(k==0) break;
        }  
        while(k>0 && j<arr.size()){
            ans.push_back(arr[j]);
            k--;
            j++;
            if(k==0) break;
        }   
        sort(ans.begin(),ans.end());
        return ans;  
    }
};