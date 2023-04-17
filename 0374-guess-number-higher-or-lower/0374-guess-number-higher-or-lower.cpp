/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        long i = 1;
        int j = n;
        
        while(i <= j){
            long  m = (i+j)/2;
            int temp = guess(m);
            if(temp == 0){
                return m;
            }else if(temp == -1){
                j = m - 1;
            }else{
                i = m + 1;
            }
        }
        return 0;
    }
};