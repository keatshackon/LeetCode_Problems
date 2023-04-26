class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int x = 0;
        for(auto q:nums) x ^= q;
        
        return x;
        
    }
};