class Solution {
public:
    
    int solve(vector<vector<int>>&grid){
        
        int row = grid.size();
        int col = grid[0].size();
        
        int w = 0;
        
        queue<pair<int,int>>q;
        
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                
                // checking for fresh orange
                if(grid[i][j] == 1){
                    w = 1;
                }
            }
        }
        
        if(q.empty()){
            if(w == 1) return 0;
            else return 1;
        }
    
        int ans = 0;
        
        
        while(!q.empty()){
           
            
            int dx[] = {-1,1,0,0};
            int dy[] = {0,0,-1,1};
            
            ans++;
            
            int n = q.size();
            
            for(int i = 0;i < n;i++){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i = 0;i < 4;i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];

                    if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col and grid[new_x][new_y] == 1){

                        grid[new_x][new_y] = 2;
                        q.push({new_x,new_y});
                    }
                }    
            }
        }
        
        for(auto q:grid){
            for(auto w:q){
                if(w == 1){
                    return 0;
                }
            }
        }
        
        return ans;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        return solve(grid)-1;

    }
};