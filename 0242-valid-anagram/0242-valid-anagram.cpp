class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int arr[26] = {0};
        int len1 = s.length();
        int len2 = t.length();
        
        if(len1 != len2) return false;
        
        for(int i = 0;i < len1;i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
    
        
        for(auto q:arr){
            if(q >= 1){
                return false;
            }
        }
        return true;
    }
};