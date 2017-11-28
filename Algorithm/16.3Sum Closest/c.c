void QuickSort(int *arr, int start, int end);
int Partition(int *arr, int start, int end);

void QuickSort(int *arr, int start, int end)
{
    if (start == end) return;    
    int index = Partition(arr, start, end);
    if (index > start) QuickSort(arr, start, index);    
    if (index < end) QuickSort(arr, index + 1, end);
}

int Partition(int *arr, int start, int end)
{
    int i = start, j = end, x = arr[start];
    while (i < j)
    {
        while (i < j && arr[j] >= x) j--;
        if (i < j) arr[i++] = arr[j];        
        while (i < j && arr[i] < x) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = x;    
    return i;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, start, end, foo, offset = INT_MAX;
    QuickSort(nums, 0, numsSize - 1);
    for(i = 0; i < numsSize - 2; i++) {
        start = i + 1;
        end = numsSize - 1;
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        while(end > start) {
            foo = nums[i] + nums[start] + nums[end] - target;
            if(abs(foo) < abs(offset)) offset = foo;
            if(offset == 0) return target;
            if(foo > 0) end--;
            else if(foo < 0) start++;
            else {
                return target;
            }
        }
    }
    return target + offset;
}
