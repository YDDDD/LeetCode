char* countAndSay(int n) {
	char* retFromNMinus1;
	char retArray[5000] = { 0 };
	int count = 0, charIndex = 0;
	char currentChar;
	if (n == 1) return "1";

	retFromNMinus1 = countAndSay(n - 1);

	currentChar = *retFromNMinus1;
	while (1) {
		if (*retFromNMinus1 != currentChar) {
			retArray[charIndex++] = '0' + count;
			retArray[charIndex++] = currentChar;
			count = 0;
			currentChar = *retFromNMinus1;
		}
		if (!*retFromNMinus1) break;

		count++;
		*retFromNMinus1++;
	}
	retArray[charIndex++] = '\0';

	char* ret = (char *)malloc(charIndex * sizeof(char));
	memcpy(ret, retArray, charIndex);

	return ret;
}
