class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>dp;
        
        dp.push_back({1});
        dp.push_back({1,1});
        
        if(numRows == 1) return {{1}};
        if(numRows == 2) return dp;
        
        for(int i = 2;i < numRows;i++){
            vector<int>temp;
            for(int j = 0;j <= i;j++){
                if(j > 0 and j < i){
                    temp.push_back(dp[i-1][j-1]+dp[i-1][j]);
                }else{
                    temp.push_back(1);
                }
            }
            dp.push_back(temp);
        }
        
        
        return dp;
    }
};