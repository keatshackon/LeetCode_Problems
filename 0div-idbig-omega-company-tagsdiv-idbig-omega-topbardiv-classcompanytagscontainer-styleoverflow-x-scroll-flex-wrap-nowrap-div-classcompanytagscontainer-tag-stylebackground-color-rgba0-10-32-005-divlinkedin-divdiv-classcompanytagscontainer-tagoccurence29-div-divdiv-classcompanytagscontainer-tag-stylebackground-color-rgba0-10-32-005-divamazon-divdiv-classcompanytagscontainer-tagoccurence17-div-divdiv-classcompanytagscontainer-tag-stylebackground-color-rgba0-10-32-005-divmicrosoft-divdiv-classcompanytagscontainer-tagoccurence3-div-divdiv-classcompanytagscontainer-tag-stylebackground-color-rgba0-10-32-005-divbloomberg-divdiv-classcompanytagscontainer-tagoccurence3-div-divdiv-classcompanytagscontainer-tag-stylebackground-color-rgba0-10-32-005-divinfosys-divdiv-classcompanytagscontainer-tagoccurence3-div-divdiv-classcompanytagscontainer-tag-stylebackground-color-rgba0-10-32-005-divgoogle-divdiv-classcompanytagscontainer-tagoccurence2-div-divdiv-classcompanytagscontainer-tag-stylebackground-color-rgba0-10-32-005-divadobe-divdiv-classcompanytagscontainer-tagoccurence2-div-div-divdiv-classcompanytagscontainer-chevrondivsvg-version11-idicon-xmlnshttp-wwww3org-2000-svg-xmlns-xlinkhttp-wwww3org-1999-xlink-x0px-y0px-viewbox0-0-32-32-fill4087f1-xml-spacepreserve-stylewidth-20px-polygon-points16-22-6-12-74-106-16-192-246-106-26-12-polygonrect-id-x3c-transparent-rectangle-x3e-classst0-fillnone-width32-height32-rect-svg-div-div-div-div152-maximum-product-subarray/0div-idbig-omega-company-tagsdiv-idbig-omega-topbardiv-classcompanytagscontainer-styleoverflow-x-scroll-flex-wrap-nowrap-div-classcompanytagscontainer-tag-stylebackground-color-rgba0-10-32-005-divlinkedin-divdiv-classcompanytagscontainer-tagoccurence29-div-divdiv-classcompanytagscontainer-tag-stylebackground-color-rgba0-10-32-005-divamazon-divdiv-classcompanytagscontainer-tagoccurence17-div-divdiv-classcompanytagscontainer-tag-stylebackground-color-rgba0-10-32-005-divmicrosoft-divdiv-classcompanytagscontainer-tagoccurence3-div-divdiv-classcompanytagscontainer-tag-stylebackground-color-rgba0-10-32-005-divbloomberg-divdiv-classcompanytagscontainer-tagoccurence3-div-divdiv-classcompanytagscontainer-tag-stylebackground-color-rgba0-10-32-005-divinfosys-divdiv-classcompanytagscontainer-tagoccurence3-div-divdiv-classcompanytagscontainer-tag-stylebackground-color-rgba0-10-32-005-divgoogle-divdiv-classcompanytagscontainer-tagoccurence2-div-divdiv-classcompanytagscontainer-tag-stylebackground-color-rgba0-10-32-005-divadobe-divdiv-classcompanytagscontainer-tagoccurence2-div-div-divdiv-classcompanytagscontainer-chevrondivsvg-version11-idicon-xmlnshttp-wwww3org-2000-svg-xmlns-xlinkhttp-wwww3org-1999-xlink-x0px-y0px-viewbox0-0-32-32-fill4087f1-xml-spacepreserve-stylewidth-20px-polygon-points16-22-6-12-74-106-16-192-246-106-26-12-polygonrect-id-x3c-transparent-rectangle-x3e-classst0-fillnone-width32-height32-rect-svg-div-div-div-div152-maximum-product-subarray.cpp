class Solution {
public:
    int maxProduct(vector<int>& A) {
        
        //By Striver Bhai
        
        int pre = 1;
        int suf = 1;
        int ans = INT_MIN;
        int n = A.size();
        
        for(int i = 0;i < n;i++){
            
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            
            pre *= A[i];
            suf *= A[n-i-1];
            int m = max(pre,suf);
            ans = max(ans,m);
        }
        return ans;
    }
};