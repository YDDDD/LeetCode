int cal(int x) {
	int ret = 0;
	while (x > 0) {
		if (ret > INT_MAX / 10) return 0;
		ret *= 10;
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int reverse(int x) {
	return x < 0 ? -cal(-x) : cal(x);
}
