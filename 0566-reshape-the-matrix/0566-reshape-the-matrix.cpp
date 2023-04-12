class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            
        
        int row = mat.size();
        int col = mat[0].size();
        
        int cnt = row * col;
        
        if((r*c) != cnt){
            return mat;
        }
        
        vector<vector<int>>ans(r,vector<int>(c,0));
        
        int x = 0;
        int y = 0;
        
        for(int i = 0;i < r; i++){
            for(int j = 0;j < c;j++){
                ans[i][j] = mat[x][y];
                y++;
                if(y == col){
                    y = 0;
                    x = x + 1;
                }
            }
        }
        
        return ans;
    }
};