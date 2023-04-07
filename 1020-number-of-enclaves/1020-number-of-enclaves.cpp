class Solution {
public:
    
    void dfs(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&vis){
        
        int row = grid.size();
        int col = grid[0].size();
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for(int i = 0;i < 4;i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col and grid[new_x][new_y] == 1
              and vis[new_x][new_y] == 0){
                
                vis[new_x][new_y] = 1;
                dfs(new_x,new_y,grid,vis);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>vis(row,vector<int>(col,0));
        
        for(int i = 0;i < col ;i++){
            
            if(grid[0][i] == 1 and vis[0][i] == 0){
                vis[0][i] = 1;
                dfs(0,i,grid,vis);    
            }
            
            if(grid[row-1][i] == 1 and vis[row-1][i] == 0){
                vis[row-1][i] = 1;
                dfs(row-1,i,grid,vis);    
            }
        }
        
        for(int i = 0;i < row ;i++){
            if(grid[i][0] == 1 and vis[i][0] == 0){
                vis[i][0] = 1;
                dfs(i,0,grid,vis);    
            }
            
            if(grid[i][col-1] == 1 and vis[i][col-1] == 0){
                vis[i][col-1] = 1;
                dfs(i,col-1,grid,vis);    
            }
        }

        
        // for(auto q:vis){
        //     for(auto w:q){
        //         cout<<w<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        int ans = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1 and vis[i][j] == 0){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};