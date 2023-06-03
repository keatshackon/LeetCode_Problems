class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        int n = grid.size();
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        if(grid[n-1][n-1] == 1 or grid[0][0] == 1){
            return -1;
        }
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        
        vis[0][0] = 1;
        
        int ans = 0,flag = 0;
    
        
        while(!q.empty()){
            
            
            int siz = q.size();
            ans++; 
            while(siz--){
                
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                if(x == n-1 and y == n-1){
                    flag = 1;
                    break;
                }


                int dx[] = {-1,1,0,1,-1,0,-1,1};
                int dy[] = {-1,1,1,0,0,-1,1,-1};

                for(int i = 0;i < 8;i++){
                    int new_x = x + dx[i];
                    int new_y = y + dy[i];

                    if(new_x >= 0 and new_x < n and new_y >= 0 and new_y < n and grid[new_x][new_y] == 0
                      and vis[new_x][new_y] == 0){
                        q.push({new_x,new_y});
                        vis[new_x][new_y] = 1;
                    }
                }
                
            }
            
            if(flag == 1) break;
        }
        
        if(flag == 0){
            return -1;
        }
        
        
        return  ans;
        
    }
};