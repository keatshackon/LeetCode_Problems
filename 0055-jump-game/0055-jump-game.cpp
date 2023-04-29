class Solution {
public:
    
    bool solve(int idx,int n,vector<int>&nums,vector<int>&dp){
        
        if(idx == (n-1)){
            return true;
        }else if(idx >= n){
            return false;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int k = nums[idx];
        bool s1 = false;
        for(int i = 1;i <= k;i++){
            s1 = solve(idx+i,n,nums,dp);
            if(s1) break;
        }
        
        return dp[idx] = s1;
    }
    
    bool canJump(vector<int>& nums) {
        
        
        int n = nums.size();
        
        vector<int>dp(n,-1);
    
    
        bool ans =  solve(0,n,nums,dp);
        
    
        return ans; 
        
        
        
    }
};