class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long l = 1;
        int r = num;
        
        while(l <= r){
            long long m = (l+r)/2;
            
            if((m*m) == num){
                return true;
            }else if((m*m) < num){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return false;
    }
};