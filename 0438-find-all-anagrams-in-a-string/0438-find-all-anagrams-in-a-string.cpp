class Solution {
public:
    vector<int> findAnagrams(string pat, string txt) {
        map<char, int> mp;
	    vector<int> ans;
	    for(int i=0;i<txt.size();i++){
	        mp[txt[i]]++;
	    }
	    int count = mp.size();
	    int i=0,j=0;
	
	    while(j<pat.size()){
	        cout<<i<<" "<<j<<endl;
	        // first we havce to check wethher that elemet is present in map or not
	        if(mp.find(pat[j])!=mp.end()){
	            mp[pat[j]]--;
	            if(mp[pat[j]]==0) count--;
	        }
	        
	        // if the size is equals to window size
	        if((j-i+1)==txt.size()){
              
	            if(count==0) ans.push_back(i);
	            if(mp.find(pat[i])!=mp.end()){  if(mp[pat[i]]==0)count++; mp[pat[i]]++;}
	            i++;
	        }
	        j++;
	      
	    }
	    return ans;
    }
};