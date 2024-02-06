class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int i = 1;
        int n = nums.size();
        int j=  n-1-1;
        
        if(n == 1) return 0;
        
        int ans = 0;
        if(nums[0] > nums[n-1]){
            ans = 0;
        }else if(nums[n-1] > nums[0]){
            ans = n-1;
        }
        
        while(i <= j){
            int m = (i+j)/2;
            
            if(nums[m] > nums[m+1] and nums[m] > nums[m-1]){
                return m;
            }else if(nums[m] > nums[m-1]){
                i++;
            }else{
                j--;
            }
            
        }
        return ans;
    }
};