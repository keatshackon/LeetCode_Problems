class Solution {
public:
    
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        
        if(i == s.length() or j == t.length()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = 1 + solve(i+1,j+1,s,t,dp);
        }else{
            return dp[i][j] = max(solve(i+1,j,s,t,dp), solve(i,j+1,s,t,dp));
        }
    }
    
        
    int longestPalindromeSubseq(string s) {
        
        string t = s;
        
        reverse(begin(t),end(t));
        
        int n = s.length();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        
        return solve(0,0,s,t,dp);
    
    }
};