int lengthOfLastWord(char* s) {
    int ret = 0;
    while(*s) {
        if(*s != ' ') {
            if(*(s - 1) == ' ')
                ret = 0;
            ret++;
        }       
        
        s++;
    }
    return ret;
}
