//Runtime: 6 ms

int youngJump(int* nums, int numsSize, int depth, int* nodeDic, int* minStep) {
	if (*nodeDic == 0 || *nodeDic > depth) *nodeDic = depth;
	else return 0;

	if (*nums >= numsSize - 1) {
		if (++depth < *minStep) *minStep = depth;
        if(depth <= 2) return -1;//hack
		return 0;//exit here
	}

	for (int i = *nums; i > 0; i--) {
		if(youngJump(nums + i, numsSize - i, depth + 1, nodeDic + i, minStep) < 0) return -1;
	}
    
    return 0;
}

int jump(int* nums, int numsSize) {
	if (numsSize < 3) return numsSize - 1;
	int *nodeDic = (int *)calloc(numsSize, sizeof(int));
	//memset(nodeDic, INT_MAX, sizeof(int) * numsSize);
	int step = INT_MAX;
	youngJump(nums, numsSize, 0, nodeDic, &step);
	return step;
}
