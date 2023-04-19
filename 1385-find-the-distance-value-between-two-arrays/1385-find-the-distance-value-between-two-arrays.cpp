class Solution {
public:
    
    bool check(vector<int>&A,int d,int m){
        
        int n = A.size();
        
        int l = 0;
        int r = n - 1;
        
        for(int i = 0;i < n;i++){
            if(abs(A[i] - m) <= d){
                return 0;
            }
        } 
        
        return 1;
    }
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        
        int len = arr1.size();
        
        sort(begin(arr2),end(arr2));
        

        int ans = 0;
        
        for(int i = 0;i < len;i++){
            if(check(arr2,d,arr1[i])){
                ans++;
            }
        }
        
        return ans;
    }
};