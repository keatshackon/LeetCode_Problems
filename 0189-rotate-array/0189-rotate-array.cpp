class Solution {
public:
    
    void reverse(vector<int>&v,int i,int j){
        
        while(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int i = 0;
        int j = nums.size() - 1;
        
        k =  k % (j+1);
        
        reverse(nums,i,j);
        reverse(nums,i,k-1);
        reverse(nums,k,j);
        
    }
};