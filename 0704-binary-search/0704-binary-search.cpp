class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int len = nums.size();
        
        if(len == 1) return nums[0] == target ? 0 : -1;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l  = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }
};