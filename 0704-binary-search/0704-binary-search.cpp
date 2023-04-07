class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 1 and nums[0] == target) return 0;
        else if (nums.size() == 1 and nums[0] != target) return -1;
        
        int i = 1;
        int j = nums.size();
    
        while(i <= j){
            int mid = (i+j) / 2;
            if(nums[mid] == target){
                return mid;
            }else if (nums[mid] > target){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        if(target == nums[0]){
            return 0;
        }
        return -1;
    }
};