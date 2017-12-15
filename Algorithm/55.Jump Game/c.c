//Runtime:3ms

bool canJump(int* nums, int numsSize) {
	int index = numsSize - 1, end = numsSize - 1;
    while(--index >= 0) {
        if(nums[index] + index >= end)
            end = index;
    }
    return end == 0;
}
