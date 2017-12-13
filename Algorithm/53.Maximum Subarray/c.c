//Runtime:3ms

int maxSubArray(int* nums, int numsSize) {
    int max = 0, ret = INT_MIN;
    
    for(int i = 0; i < numsSize; i++) {
        max += nums[i];
        ret = ret > max ? ret : max;
        max = max > 0 ? max : 0;
    }   
    return ret;
}
