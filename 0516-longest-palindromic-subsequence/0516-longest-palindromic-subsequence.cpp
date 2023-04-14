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
        
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //return solve(0,0,s,t,dp);
            
        
        vector<vector<int>>dp2(n+1,vector<int>(n+1,0));
        
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == t[j-1]){
                    dp2[i][j] = 1 + dp2[i-1][j-1];
                }else{
                    int s1 = 0;
                    int s2 = 0;
                    
                    s1 = dp2[i-1][j];
                    s2 = dp2[i][j-1];
                            
                    dp2[i][j] = max(s1,s2);
                }
            }
        }
        
        
        return dp2[n][n];
        
        
        
        
        
    
    }
};