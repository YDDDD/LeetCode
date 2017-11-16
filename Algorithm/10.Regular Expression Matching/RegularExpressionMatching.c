//Runtime: 18 ms

bool isMatch(char* s, char* p) {
    if(*s == '\0') {
        if(*p == '\0') {
            return true;//exit here
        } else if(*p == '*') {
            return isMatch(s - 1, p + 1) || isMatch(s, p + 1);
        } else if((++p) && *p == '*') {
            return isMatch(s, ++p);
        } else {
            return false;
        }
    }
    switch (*p) {
        case '*':
            if(isMatch(s - 1, p + 1)) {
                return true;
            }
            while(*s != '\0' && (*s == *(p - 1) || *(p - 1) == '.')) {
                if(isMatch(s, p + 1)) return true;
                s++;
            }
            return isMatch(s, ++p);
        case '.':
            return isMatch(++s, ++p);
            break;
        case '\0':
            return false;
        default:
            if(*p == *s) return isMatch(++s, ++p);
            else if(*(++p) == '*') return isMatch(s, ++p);
            else return false;
    }
}
