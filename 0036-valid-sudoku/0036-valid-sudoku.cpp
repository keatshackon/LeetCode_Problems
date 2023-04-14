class Solution {
public:
    
    bool isValid(vector<vector<char>>&board,int x,int y,char ch){
        
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0;i < 9;i++){
            
            if(ch == board[i][y]){
                return false;
            }
            
            if(ch == board[x][i]){
                return false;
            }
            
            if(ch == board[3*(x/3) + i/3][3*(y/3) + i%3]){
                return false;
            }
        }

        return 1;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
    
        
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    char ch = board[i][j];
                    board[i][j] = '.';
                    if(!isValid(board,i,j,ch)){
                        return 0;    
                    }
                    board[i][j] = ch;
                }
            }
        }
        return 1;   
    }
};






