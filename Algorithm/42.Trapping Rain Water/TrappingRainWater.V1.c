//Runtime 6ms
//Beats 51.11%

void Search(int *height, int start, int from, int maxofOtherSide, int* ret) {
	if ((from == -1 && start < 0) || (from != 0 && start == from)) return;

	int maxIndex = start, maxVal = 0;
	int step = from < 0 ? -1 : 1;
	for (int i = start; i != from; i += step) {
		if (height[i] >= maxVal) {
			maxIndex = i;
			maxVal = height[i];
		}
	}

	int depth = maxofOtherSide > maxVal ? maxVal : maxofOtherSide;
	for (int i = start; i != maxIndex; i += step) {
		*ret += height[i] < depth ? depth - height[i] : 0;
	}

	Search(height, maxIndex + step, from, depth, ret);
}

int trap(int* height, int heightSize) {
	if (heightSize < 3) return 0;
	int ret = 0;
	
	int maxIndex = 0, maxVal = 0;
	for (int i = 0; i < heightSize; i++) {
		if (height[i] > maxVal) {
			maxIndex = i;
			maxVal = height[i];
		}
	}

	Search(height, maxIndex + 1, heightSize, maxVal, &ret);
	Search(height, maxIndex - 1, -1, maxVal, &ret);

	return ret;
}
