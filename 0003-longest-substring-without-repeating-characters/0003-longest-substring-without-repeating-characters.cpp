class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n  = s.length();
        
        if(n == 0) return 0;
        
        map<char,int>m;
        
        int i = 0,j = 0;
        
        int ans = 1;
        
        while(j < n){
            if(m.count(s[j]) == 0){
                m[s[j]] = 1;
                ans = max(ans,(int)m.size());
            }else{
                
                while(s[i] != s[j]){
                    m[s[i]]--;
                    if(m[s[i]] == 0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                i++;
                ans = max(ans,(int)m.size());
            }
            j++;
        }
        
        return ans;   
    }
};