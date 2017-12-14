//Runtime:0ms
//emmmm

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int top = 1, buttom = matrixRowSize - 1, left = 0, right = matrixColSize - 1, index = 0, posX = -1, posY = 0, retSize = matrixRowSize * matrixColSize;
	int *ret = (int *)malloc(retSize * sizeof(int));
	while (index < retSize) {
		while (++posX <= right && index < retSize)
			ret[index++] = matrix[posY][posX];
		right--, posX--;
		while (++posY <= buttom && index < retSize)
			ret[index++] = matrix[posY][posX];
		buttom--, posY--;
		while (--posX >= left && index < retSize)
			ret[index++] = matrix[posY][posX];
		left++, posX++;
		while (--posY >= top && index < retSize)
			ret[index++] = matrix[posY][posX];
		top++, posY++;
	}
	return ret;
}
