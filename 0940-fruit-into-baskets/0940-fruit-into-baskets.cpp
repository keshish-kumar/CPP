class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sum =0;
        int ans = 2;
        int i=0,j=0;
        if(fruits.size()==1) return 1;
        map<int,int> mp;
        while(j<fruits.size()){
            
            mp[fruits[j]]++;
            while(!mp.empty() && mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
           
                ans=max(ans,(j-i+1));
            

            j++;

        }
        return ans;
    }
};