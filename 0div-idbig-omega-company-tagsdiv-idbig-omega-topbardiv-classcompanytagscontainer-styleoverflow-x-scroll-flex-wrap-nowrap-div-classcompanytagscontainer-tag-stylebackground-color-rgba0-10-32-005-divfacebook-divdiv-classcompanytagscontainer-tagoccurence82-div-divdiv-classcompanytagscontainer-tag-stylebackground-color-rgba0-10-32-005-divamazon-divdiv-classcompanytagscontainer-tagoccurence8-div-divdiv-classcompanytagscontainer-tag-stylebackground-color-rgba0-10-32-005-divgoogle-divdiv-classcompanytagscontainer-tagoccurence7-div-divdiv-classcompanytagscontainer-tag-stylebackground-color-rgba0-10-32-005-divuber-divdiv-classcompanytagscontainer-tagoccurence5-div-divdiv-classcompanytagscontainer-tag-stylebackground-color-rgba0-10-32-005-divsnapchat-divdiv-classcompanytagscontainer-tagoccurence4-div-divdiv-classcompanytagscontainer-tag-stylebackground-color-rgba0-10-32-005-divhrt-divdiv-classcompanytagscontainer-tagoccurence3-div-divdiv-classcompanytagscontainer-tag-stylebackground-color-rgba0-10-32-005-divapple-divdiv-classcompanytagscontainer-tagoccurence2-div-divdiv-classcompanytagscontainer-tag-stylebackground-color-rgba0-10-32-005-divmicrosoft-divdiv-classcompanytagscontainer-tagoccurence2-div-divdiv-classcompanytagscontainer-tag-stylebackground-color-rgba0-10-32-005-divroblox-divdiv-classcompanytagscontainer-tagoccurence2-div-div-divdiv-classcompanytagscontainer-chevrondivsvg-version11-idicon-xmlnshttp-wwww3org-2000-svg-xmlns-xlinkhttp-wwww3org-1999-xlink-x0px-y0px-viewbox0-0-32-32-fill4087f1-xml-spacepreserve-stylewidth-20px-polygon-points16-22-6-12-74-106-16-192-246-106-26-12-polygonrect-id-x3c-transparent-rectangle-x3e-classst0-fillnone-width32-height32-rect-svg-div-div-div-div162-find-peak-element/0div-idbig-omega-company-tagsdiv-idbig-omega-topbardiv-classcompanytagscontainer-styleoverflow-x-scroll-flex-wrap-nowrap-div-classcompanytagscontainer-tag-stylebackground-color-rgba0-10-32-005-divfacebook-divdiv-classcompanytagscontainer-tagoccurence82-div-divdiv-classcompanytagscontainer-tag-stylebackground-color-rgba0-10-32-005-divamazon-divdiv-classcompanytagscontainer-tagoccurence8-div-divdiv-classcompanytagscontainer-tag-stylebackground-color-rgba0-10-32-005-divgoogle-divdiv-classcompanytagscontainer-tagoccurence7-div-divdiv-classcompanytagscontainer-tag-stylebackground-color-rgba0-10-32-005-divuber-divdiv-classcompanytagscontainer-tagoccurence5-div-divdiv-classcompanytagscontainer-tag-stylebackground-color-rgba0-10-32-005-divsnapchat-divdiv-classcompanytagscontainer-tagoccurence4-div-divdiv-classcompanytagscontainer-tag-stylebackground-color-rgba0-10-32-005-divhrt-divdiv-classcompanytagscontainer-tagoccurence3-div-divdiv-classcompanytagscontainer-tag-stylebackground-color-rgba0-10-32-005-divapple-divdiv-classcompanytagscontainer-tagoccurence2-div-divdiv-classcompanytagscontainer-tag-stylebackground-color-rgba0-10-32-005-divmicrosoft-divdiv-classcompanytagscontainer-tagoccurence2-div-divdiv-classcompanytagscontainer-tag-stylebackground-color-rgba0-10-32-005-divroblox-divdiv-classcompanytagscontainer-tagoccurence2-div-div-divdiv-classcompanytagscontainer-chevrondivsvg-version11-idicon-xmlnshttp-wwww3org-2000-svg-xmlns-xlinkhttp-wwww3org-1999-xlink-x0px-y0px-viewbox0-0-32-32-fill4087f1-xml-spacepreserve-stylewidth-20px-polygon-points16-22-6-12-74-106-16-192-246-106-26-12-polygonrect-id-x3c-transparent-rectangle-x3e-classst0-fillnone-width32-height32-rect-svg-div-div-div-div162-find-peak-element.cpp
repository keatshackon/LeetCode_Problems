class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int i = 1;
        int n = nums.size();
        
        if(n == 1) return 0;
        int ans = 0;
        if(nums[0] < nums[n-1]){
            ans = n-1;
        }else if(nums[n-1] < nums[0]){
            ans = 0;
        }
        
        for(;i<n-1;i++){
            if(nums[i] > nums[i-1] and nums[i] > nums[i+1]){
                return i;
            }
        }
        return ans;
    }
};