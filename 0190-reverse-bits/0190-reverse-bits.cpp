class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
            
        uint32_t ans = 0; 
        
        int j = 31;
            
        for(int i = 0;i <= 31;i++){
            if((n & (1<<i)) >= 1){
                ans = ans | (1 << j);
            }
            j--;
        }
        
        return ans;
    }
};