class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;
        int k = n + m - 1;
        int j = n - 1;
        
        while(i >= 0 and j >= 0){
            if(nums1[i] <= nums2[j]){
                nums1[k] = nums2[j];
                j--;
                k--;
            }else{
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        
        while(k >= 0 and j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
        for(int i = 0;i < n+m;i++){
            cout<<nums1[i]<<" ";
        }
    }
};