//TLE..

bool isMatch(char* s, char* p) {
    if(*s == '\0') {
        switch(*p) {
            case '\0': return true;
            case '*': return isMatch(s, ++p);
            default: return false;
        }
    }
    
    switch(*p) {
        case '?' : return isMatch(++s, ++p);
        case '*' :
            if(*(p - 1) == '*') return isMatch(s, ++p);
            while(*s != '\0') {
                if(isMatch(s++, p + 1)) return true;
            }
            return isMatch(s, ++p);
        case '\0': return false;
        default: return *s == *p ? isMatch(++s, ++p) : false;
    }
    
    return false;
}
