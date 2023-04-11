class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        
        int row = board.size();
        int col = board[0].size();
        
        
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                
                
                int dx[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
                int dy[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
                int cnt = 0;
                
                for(int k = 0;k < 8;k++){
                    
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];

                    if(new_x >= 0 and new_x < row and new_y >= 0 and new_y < col){
                        if(board[new_x][new_y] == 1 or board[new_x][new_y] == -2){
                            cnt++;
                        }
                    }
                }
            
                
                if(cnt < 2){
                    if(board[i][j] == 1){
                        board[i][j] = -2;
                    }
                }else if(cnt == 3 or cnt == 2){
                    if((board[i][j] == 0) and cnt == 3){
                        board[i][j] = -1;
                    }
                }else {
                    if(board[i][j] == 1){
                        board[i][j] = -2;   
                    }
                }
            }
        }
        
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(board[i][j] == -1){
                    board[i][j] = 1;
                }else if(board[i][j] == -2){
                    board[i][j] = 0;
                }
            }
        }
        
    }
};