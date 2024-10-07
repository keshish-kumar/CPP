class Solution {
public:
    bool solve(string & s, string & p, int i, int j){ // i for string and j for pattern
            if(j==p.size() && i==s.size()){
                return true;
            }
            if(i>=s.size()){
                while(j<p.size()){
                 if( ((j+1)<p.size()) && p[j+1]=='*'){
                        j=j+2;
                    }
                    else{
                        return false;
                    }
                }
                return true;
            }
            if(j>=p.size()) return false;

            // if he character mathes
            if((j + 1) < p.size() && p[j + 1] == '*'){  // Correct handling of '*' in the pattern
            // Case: '*' matches 0 occurrences
            if(solve(s, p, i, j + 2)) {  
                return true;
            }
            // Case: '*' matches 1 or more occurrences
            if((s[i] == p[j] || p[j] == '.') && solve(s, p, i + 1, j)) {  
                return true;
            }
        } else if(s[i] == p[j] || p[j] == '.'){  // Regular character match or '.'
            return solve(s, p, i + 1, j + 1);
        }

        return false;  // No match found
            

    }
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};