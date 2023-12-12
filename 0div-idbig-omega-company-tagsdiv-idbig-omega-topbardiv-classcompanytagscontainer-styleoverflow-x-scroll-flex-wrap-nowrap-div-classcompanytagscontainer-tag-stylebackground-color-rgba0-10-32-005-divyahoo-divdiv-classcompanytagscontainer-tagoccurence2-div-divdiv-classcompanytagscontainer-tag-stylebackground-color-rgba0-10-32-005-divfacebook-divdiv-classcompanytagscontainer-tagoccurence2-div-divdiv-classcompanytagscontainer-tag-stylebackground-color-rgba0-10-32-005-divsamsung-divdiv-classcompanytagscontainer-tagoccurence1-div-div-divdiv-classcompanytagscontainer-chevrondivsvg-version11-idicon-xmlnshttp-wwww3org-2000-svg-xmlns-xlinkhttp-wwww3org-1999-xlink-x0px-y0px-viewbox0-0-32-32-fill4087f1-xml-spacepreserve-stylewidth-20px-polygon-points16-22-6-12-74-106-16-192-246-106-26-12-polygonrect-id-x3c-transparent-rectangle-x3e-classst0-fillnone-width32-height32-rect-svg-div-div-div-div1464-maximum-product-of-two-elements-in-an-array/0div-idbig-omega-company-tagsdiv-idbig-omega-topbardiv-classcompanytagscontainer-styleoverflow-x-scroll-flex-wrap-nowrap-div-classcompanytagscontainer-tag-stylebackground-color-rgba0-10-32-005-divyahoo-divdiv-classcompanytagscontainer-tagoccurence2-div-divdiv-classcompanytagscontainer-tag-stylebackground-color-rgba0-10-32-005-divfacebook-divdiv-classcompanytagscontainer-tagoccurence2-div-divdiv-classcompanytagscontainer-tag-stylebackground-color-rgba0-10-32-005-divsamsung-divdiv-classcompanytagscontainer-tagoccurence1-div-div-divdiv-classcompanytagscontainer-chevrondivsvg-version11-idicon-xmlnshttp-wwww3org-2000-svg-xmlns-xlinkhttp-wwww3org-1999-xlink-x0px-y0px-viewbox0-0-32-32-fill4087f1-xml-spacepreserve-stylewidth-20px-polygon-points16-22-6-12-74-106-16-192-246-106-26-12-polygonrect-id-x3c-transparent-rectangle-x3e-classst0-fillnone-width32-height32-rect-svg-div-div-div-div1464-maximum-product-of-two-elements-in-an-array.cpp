class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int largest = -1;
        int SecondLargest = -1;
        int len = nums.size();
        
        for(int i=0;i<len;i++){
            if(nums[i] > largest){
                SecondLargest = largest;
                largest = nums[i];
                
            }else if(SecondLargest < nums[i]){
                SecondLargest = nums[i];
            }
        }
        return (largest-1) * (SecondLargest-1);
    }
};