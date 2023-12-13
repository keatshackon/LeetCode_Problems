class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        
        int n = mat.size();
        int m = mat[0].size();
        
        int cnt = 0;
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                
                if(mat[i][j] == 1){
                    
                    int f = 1;
                    for(int k = 0;k < m;k++){
                        if(mat[i][k] == 1 and k != j){
                            f = 0;
                            break;
                        }
                    }
                    
                    for(int k = 0;k < n;k++){
                        if(mat[k][j] == 1 and k != i){
                            f = 0;
                            break;
                        }
                    }
                    if(f == 1){
                        cnt++;
                    }   
                }
            }
        }
        
        return cnt;
        
    }
};