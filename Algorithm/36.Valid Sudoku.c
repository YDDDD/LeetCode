bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int row[9][9] = {0}, col[9][9] = {0}, rect[3][3][9] = {0};
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] != '.') {
                int val = board[i][j] - '0' - 1;
                if(row[i][val] != 0 || col[j][val] != 0 || rect[i / 3][j / 3][val] != 0) return false;
                row[i][val] = 1;
                col[j][val] = 1;
                rect[i / 3][j / 3][val] = 1;
            }
        }
    }
    
    return true;
}
