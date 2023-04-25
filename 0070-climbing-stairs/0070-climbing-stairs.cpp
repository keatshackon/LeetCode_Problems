class Solution {
    
    
    // Method-1
    int solve(int n,vector<int>&dp){
        
        if(n == 1 or n == 2) return n;
        
        if(dp[n] != -1){
            return dp[n];
        }
    
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    
public:
    int climbStairs(int n) {
        
        if(n <= 2){
            return n;
        }
        
        // vector<int>dp(n+1,-1);
        // dp[1] = 1;
        // dp[2] = 2;
        // solve(n,dp);
        // return dp[n];
        
        
        // Second - 2.
        int a = 1,b = 2;
        
        for(int i = 3;i <= n;i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};