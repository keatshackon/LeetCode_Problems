class Solution {
public:
     
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        
        
         int row = A.size();
        int col = A[0].size();


        vector<vector<int>>dis(row,vector<int>(col,0));
        vector<vector<int>>vis(row,vector<int>(col,0));

        queue<pair<int,int>>q;

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(A[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};

            for(int i = 0;i < 4;i++){
                int nrow = x + dx[i];
                int ncol = y + dy[i]; 

                if(nrow >= 0 and nrow < row and ncol >= 0 and ncol < col and 
                vis[nrow][ncol] == 0 and A[nrow][ncol] == 1){

                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                    dis[nrow][ncol] = dis[x][y] + 1;
                }
            }
        }
        
        return dis;
        
    }
};