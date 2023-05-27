class Solution {
public:
    
    int solve(int idx,vector<int>&c,vector<int>&dp){
        
        if(idx >= c.size()){
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int s1 = c[idx] + solve(idx+1,c,dp);
        
        int s2 = c[idx] + solve(idx+2,c,dp);
        
        return dp[idx] = min(s2,s1);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n  = cost.size();
        vector<int>dp(n,-1);
        
        
//         solve(0,cost,dp);
        
//         return min(dp[0],dp[1]);
        
        
        dp[0] = cost[0];
        dp[1] = min(cost[0],cost[1]);
        
        for(int i = n-1 ;i >= 0;i--){
            
            int s1 = 0;
            if(i < n-1){
                s1 = dp[i+1];
            }
            int s2 = 0;
            if(i < n-2){
                s2 = dp[i+2];
            }

            dp[i] = cost[i] + min(s2,s1);
        }
        
        
        return min(dp[0],dp[1]);
    }
};