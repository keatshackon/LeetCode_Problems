class Solution {
public:
    int arrangeCoins(int n) {
        
        long long l = 1;
        int r = n;
        
        int ans = -1;
        
        while(l <= r){
            long long mid = (l+r)/2;
            
            long long res = ((mid) * (mid + 1))/2;
            
            if(res > n){
                r = mid - 1;
            }else{
                ans = mid;
                l = mid + 1;
            }
            
        }
        return ans;
    }
};