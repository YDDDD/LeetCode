//Runtime: 3 ms
bool push(char** board, int rowIndex, int colIndex, int usedH[9][9], int usedV[9][9], int usedRect[9][9]) {

	if (rowIndex == 9)
		return true;

	int nextRow = rowIndex, nextCol = colIndex + 1;
	if (nextCol == 9) {
		nextCol = 0;
		nextRow++;
	}

	if (board[rowIndex][colIndex] != '.')
		return push(board, nextRow, nextCol, usedH, usedV, usedRect);
	else {

		for (int i = 1; i < 10; i++) {

			if (usedH[rowIndex][i - 1] == 1 || usedV[colIndex][i - 1] == 1 || usedRect[3 * (rowIndex / 3) + (colIndex / 3)][i - 1] == 1)
				continue;

            board[rowIndex][colIndex] = '0' + i;

			usedH[rowIndex][i - 1] = 1;
			usedV[colIndex][i - 1] = 1;
			usedRect[3 * (rowIndex / 3) + (colIndex / 3)][i - 1] = 1;
			if (push(board, nextRow, nextCol, usedH, usedV, usedRect)) {
				return true;
			}
			else {
				board[rowIndex][colIndex] = '.';
                usedH[rowIndex][i - 1] = 0;
                usedV[colIndex][i - 1] = 0;
                usedRect[3 * (rowIndex / 3) + (colIndex / 3)][i - 1] = 0;
            }
		}
		return false;
	}
}

//entry
void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	int usedH[9][9] = { 0 }, usedV[9][9] = { 0 }, usedRect[9][9] = { 0 };

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				usedH[i][board[i][j] - '0' - 1] = 1;
				usedV[j][board[i][j] - '0' - 1] = 1;
				usedRect[3 * (i / 3) + (j / 3)][board[i][j] - '0' - 1] = 1;
			}
		}
	}

	push(board, 0, 0, usedH, usedV, usedRect);
}
