class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int>ans;
        int j = n;
        
        for(int i = n-1;i >= 0 ;i--){
            if(nums[i] >= 0){
                j = i;
            }    
        }
        
        int k = j - 1;
        
        while(j < n and k >= 0){
            if(nums[j] < abs(nums[k])){
                ans.push_back(nums[j]*nums[j]);
                j++;
            }else{
                ans.push_back(nums[k]*nums[k]);
                k--;
            }
        }
        
        while(j < n){
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        
        while(k >= 0){
            ans.push_back(nums[k]*nums[k]);
            k--;
        }
        
        return  ans;
    }
};