class Solution {
public:
    
    int solve(int idx,int k,vector<vector<int>>&piles,vector<vector<int>>&dp){
        
        if(k == 0 or idx == piles.size()){
            return 0;
        }
        
        if(dp[idx][k] != -1){
            return dp[idx][k];
        }
        
        int s1 = solve(idx+1,k,piles,dp);
        int s2 = 0;
        
        int temp = min(k,(int)piles[idx].size());
        
        for(int i = 0;i < temp;i++){
            s2 += piles[idx][i];
            s1 = max(s1,s2 + solve(idx+1,k-(i+1),piles,dp));
        }
        return dp[idx][k] = s1;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        
        return solve(0,k,piles,dp);
    }
};