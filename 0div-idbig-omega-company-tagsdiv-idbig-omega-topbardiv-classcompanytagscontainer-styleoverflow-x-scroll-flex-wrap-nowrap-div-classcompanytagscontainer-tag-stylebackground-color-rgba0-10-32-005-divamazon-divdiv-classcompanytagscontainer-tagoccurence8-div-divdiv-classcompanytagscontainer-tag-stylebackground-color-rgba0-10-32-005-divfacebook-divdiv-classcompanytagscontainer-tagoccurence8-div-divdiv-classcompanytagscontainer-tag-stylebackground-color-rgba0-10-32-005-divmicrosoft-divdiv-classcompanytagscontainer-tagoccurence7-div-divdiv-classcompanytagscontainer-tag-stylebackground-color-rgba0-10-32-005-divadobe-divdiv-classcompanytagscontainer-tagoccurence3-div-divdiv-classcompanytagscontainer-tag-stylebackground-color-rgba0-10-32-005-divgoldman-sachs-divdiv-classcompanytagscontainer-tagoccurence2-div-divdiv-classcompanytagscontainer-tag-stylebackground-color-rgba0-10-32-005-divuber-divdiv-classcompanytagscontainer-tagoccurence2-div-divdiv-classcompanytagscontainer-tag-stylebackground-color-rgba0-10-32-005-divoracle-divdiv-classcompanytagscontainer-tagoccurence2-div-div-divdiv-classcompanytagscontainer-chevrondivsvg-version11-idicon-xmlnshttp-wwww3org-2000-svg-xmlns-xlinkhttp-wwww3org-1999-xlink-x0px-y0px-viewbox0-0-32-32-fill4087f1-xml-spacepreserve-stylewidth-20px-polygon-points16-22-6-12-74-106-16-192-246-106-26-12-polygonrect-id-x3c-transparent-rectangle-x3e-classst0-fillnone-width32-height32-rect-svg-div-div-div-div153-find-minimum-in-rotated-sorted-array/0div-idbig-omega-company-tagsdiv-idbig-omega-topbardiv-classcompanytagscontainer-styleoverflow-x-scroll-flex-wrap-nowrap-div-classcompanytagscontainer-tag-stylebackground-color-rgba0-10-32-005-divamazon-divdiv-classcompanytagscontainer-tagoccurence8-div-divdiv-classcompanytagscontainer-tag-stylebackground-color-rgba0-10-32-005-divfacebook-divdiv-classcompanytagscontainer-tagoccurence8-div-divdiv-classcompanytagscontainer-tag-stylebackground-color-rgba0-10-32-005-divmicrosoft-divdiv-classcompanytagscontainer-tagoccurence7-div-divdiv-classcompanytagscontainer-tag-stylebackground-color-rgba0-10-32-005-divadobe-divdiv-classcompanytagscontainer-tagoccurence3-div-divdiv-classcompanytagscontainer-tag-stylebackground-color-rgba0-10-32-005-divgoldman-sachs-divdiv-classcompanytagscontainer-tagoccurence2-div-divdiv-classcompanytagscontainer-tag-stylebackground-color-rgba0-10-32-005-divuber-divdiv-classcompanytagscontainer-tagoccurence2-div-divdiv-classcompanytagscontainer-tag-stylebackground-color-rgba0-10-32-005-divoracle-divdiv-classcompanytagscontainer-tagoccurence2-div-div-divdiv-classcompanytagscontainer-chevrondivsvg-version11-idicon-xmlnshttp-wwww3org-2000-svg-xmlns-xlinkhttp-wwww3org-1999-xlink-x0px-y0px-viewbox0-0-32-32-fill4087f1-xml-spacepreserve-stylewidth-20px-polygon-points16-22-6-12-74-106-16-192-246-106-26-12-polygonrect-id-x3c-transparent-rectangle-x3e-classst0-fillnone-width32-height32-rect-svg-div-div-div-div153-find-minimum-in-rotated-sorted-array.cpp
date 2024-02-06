class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l = 1;
        int k = n - 2;
        
        if(n == 1){
            return nums[0];
        }
        
        if(nums[0] < nums[n-1]){
            return nums[0];
        }else if (nums[n-1] < nums[n-2] and nums[n-1] < nums[0]){
            return nums[n-1];
        }
        
        while(l <= k){
            int m = (l+k)/2;
            
            if(nums[m] < nums[m-1] and nums[m] < nums[m+1] ){
                return nums[m];
            }else if(nums[m] > nums[0]){
                l++;
            }else{
                k--;
            }
        }
        return 0;
    }
};