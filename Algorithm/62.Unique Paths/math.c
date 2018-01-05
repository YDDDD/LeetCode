//runtime:9ms

int uniquePaths(int m, int n) {
    if(m == 1 || n == 1) return 1;
    
    if(--n < --m) {
        int foo = n;
        n = m;
        m = foo;
    }
    
    long ret = 1;
    for(int i = n+1, j=1; i <= m+n; i++, j++){
        ret *= i;
        ret /= j;
    }

    return (int)ret;
    
}
