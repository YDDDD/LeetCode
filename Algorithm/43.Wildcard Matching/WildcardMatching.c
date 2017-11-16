//Runtiem : 28ms
//Beat 76.19%

int myMatch(char *s, char*p) {
	//0:false 1:true 2:match fail and end loop
	if (*s == '\0') {
		while (*p == '*') ++p;
		return *p ? 0 : 1;
	}
	if (*p == '*') {
		if (*(p - 1) == '*') return myMatch(s, ++p);
		do {
			int ret = myMatch(s++, p + 1);
			if(ret == 0) continue;
			if(ret == 2) return 2;
			if(ret == 1) return 1;
		} while (*s);
		return myMatch(s, p) == 1 ? 1 : 2;
	}
	else return *p == '?' || *s == *p ? myMatch(++s, ++p) : 0;
}

bool isMatch(char* s, char* p) {
	return myMatch(s, p) == 1;
}
