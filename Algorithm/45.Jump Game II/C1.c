//Runtime:7ms

int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0;
    int start=0, end=0, step = 0;
    while (true) {
        step++;
        int temStart=start, temEnd=end;
        start=end+1;
        for(int i=temStart;i<=temEnd;i++) {
            if (i + nums[i] >end) end=i+nums[i];
        }
        if(end>=numsSize-1) return step;
    }
}
