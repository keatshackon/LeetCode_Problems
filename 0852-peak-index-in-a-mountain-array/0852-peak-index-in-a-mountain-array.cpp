class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0;
        int r = arr.size()-1;
    
        l = 1;
        r = r - 1;
        
        while(l <= r){
            int m = (l+r)/2;
            
            if(arr[m] > arr[m-1] and arr[m] > arr[m+1]){
                return m;
            }else if(arr[m] > arr[m-1]){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return 0;
    }
};