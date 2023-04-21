class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0,r = nums.size()-1;
        int idx1 = -1,idx2 = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                idx1 = m;
                r = m - 1;
            }else if(nums[m] > target){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        if(idx1 == -1){
            return {-1,-1};
        }
        l = 0;
        r = nums.size() - 1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                idx2 = m;
                l = m + 1;
            }else if(nums[m] > target){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return {idx1,idx2};
    }
};