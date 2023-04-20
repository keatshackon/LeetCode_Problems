class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        
        int l = 0;
        int r = letters.size()-1;
        
        char ans = '$';
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(letters[mid] == target){
                l = mid + 1;
            }else if(letters[mid] > target){
                ans = letters[mid];
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        if(ans == '$'){
            return letters[0];
        }
        return ans;
    }
};