class Solution {
public:
    
    void solve(int x,int y,int color,int target,vector<vector<int>>&image,vector<vector<int>>&vis){
        
        int row = image.size();
        int col = image[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i = 0;i < 4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col and image[new_x][new_y] ==
              target and vis[new_x][new_y] == -1){
                
                vis[new_x][new_y] = color;
                solve(new_x,new_y,color,target,image,vis);
            }
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int row = image.size();
        int col = image[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,-1));
        
        
        int target = image[sr][sc];
        vis[sr][sc] = color;
        solve(sr,sc,color,target,image,vis);
        
        
        
    
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(vis[i][j] == -1){
                    vis[i][j] = image[i][j];
                }
            }
        }
        
        
        return vis;  
    }
};










