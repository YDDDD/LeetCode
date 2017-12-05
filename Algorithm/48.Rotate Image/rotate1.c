void reverseVertical(int ** matrix, int rowSize, int colSize) {
    int foo;
    for(int i = 0; i < rowSize / 2; i++) {
        for(int j = 0; j < colSize; j++) {
            foo = matrix[i][j];
            matrix[i][j] = matrix[rowSize - 1 - i][j];
            matrix[rowSize - 1 - i][j] = foo;
        }
    }
}

void reverseDiagonal(int** matrix, int rowSize, int colSize) {
    int foo;
    for(int i = 0; i < rowSize; i++) {
        for(int j = i + 1; j < colSize; j++) {
            foo = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = foo;
        }
    }
}

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    reverseVertical(matrix, matrixRowSize, matrixColSize);
    reverseDiagonal(matrix, matrixRowSize, matrixColSize);
}
