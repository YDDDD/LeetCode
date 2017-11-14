//

double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n < 0) {
        if(n == INT_MIN)
            return (myPow(1 / x, INT_MAX) / x);
        else
            return myPow(1 / x, -n);
    }
    return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, (n - 1) / 2);
}
