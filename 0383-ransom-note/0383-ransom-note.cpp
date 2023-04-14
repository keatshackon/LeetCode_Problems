class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int arr[26] = {0};
        
        int len1 = magazine.length();
        int len2 = ransomNote.length();
        
        for(int i = 0;i < len1;i++){
            arr[magazine[i] - 'a']++;
        }
        
        for(int i = 0;i < len2;i++){
            if(arr[ransomNote[i]- 'a'] >= 1){
                arr[ransomNote[i]- 'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};