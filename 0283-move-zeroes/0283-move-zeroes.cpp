class Solution {
public:
    void moveZeroes(vector<int>& nums) {
            
        int i = 0;
        int j = 0;
        int n = nums.size();
        
        while(i < n and j < n){
            
            while(i < n and nums[i] != 0){
                i++;
            }
            if(i == n) break;
            j = i + 1;
            
            while(j < n and nums[j] == 0){
                j++;
            }
            
            if(j == n) break;
            
            swap(nums[i],nums[j]);
            i++;
        }
    }
};