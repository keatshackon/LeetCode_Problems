class Solution {
public:
    
    void solve(int x,int y,int &cnt,vector<vector<int>>&grid,vector<vector<int>>&vis){
        
        int row = grid.size();
        int col = grid[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i = 0;i < 4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col and grid[new_x][new_y] == 1 
               and !vis[new_x][new_y]){
                
                cnt++;
                vis[new_x][new_y] = 1;
                solve(new_x,new_y,cnt,grid,vis);
            }
        }
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
    
        int ans = 0;
        
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    int cnt = 0;
                    vis[i][j] = 1;
                    cnt++;
                    solve(i,j,cnt,grid,vis);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
       
    }
};