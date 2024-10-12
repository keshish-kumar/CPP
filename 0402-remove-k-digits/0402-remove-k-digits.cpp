class Solution {
public:
    string removeKdigits(string num, int k) {
      
        if(k==num.size()) return "0";
      
        stack<char> temp;
        int i=0;
        while(i<num.size()){
            if(temp.empty() || temp.top()<=(num[i])){
                temp.push(num[i]);
                i++;
            }
            else{
                while(!temp.empty() && k>0 && (num[i])<temp.top()){
                    temp.pop();
                    k--;
                }
                if(k==0) break;
                temp.push(num[i]);
                i++;

            }
            
        }
        while(k--) temp.pop();
        while(i<num.size()){ temp.push(num[i]);i++;}

        string ans="";
        while(!temp.empty()){
            ans += temp.top();
            temp.pop();
        }
        reverse(ans.begin(),ans.end());

       i=0;
       while(i<ans.size() && ans[i]=='0') {i++;}
       ans = ans.substr(i);
      return ans==""?"0":ans;
    }
};