void push(char c, char *stack, int *len) {
    stack[*len] = c;
    *len = *len + 1;
}

char pop(char *stack, int *len) {
    *len = *len - 1;
    return stack[*len];
}

bool isValid(char* s) {
    char *stack = (char *)malloc(5000);
    int len = 0;
    
    while(s) {
        switch(*s) {
            case '{':
                push('{', stack, &len);
                break;
            case '(':
                push('(', stack, &len);
                break;
            case '[':
                push('[', stack, &len);
                break;
            case '}':
                if(pop(stack, &len) != '{') return false;
                break;
            case ')':
                if(pop(stack, &len) != '(') return false;
                break;
            case ']':
                if(pop(stack, &len) != '[') return false;
                break;
            case '\0':
                return len == 0;
            default:
                return false;
        }
        s++;
    }
    
    free(stack);
    return true;
}
