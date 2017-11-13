int maxArea(int* height, int heightSize) {
    int *i = height, *j = i + heightSize - 1, max = 0;
    while(j > i) {
        int h = *i > *j ? *j : *i;
        int area = h * (j - i);
        if (area > max) max = area;
        while(j > i && *j <= h) j--;
        while(j > i && *i <= h) i++;
    }
    return max;
}
