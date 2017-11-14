//Runtime:Runtime: 16 ms
//Beats 64.61%

int myAtoi(char* str) {
    int value = 0, sign = 1;
    while(*str == ' ') str++;
    if(*str == '+' || *str == '-') {
        sign = *str == '-' ? -1 : 1;
        str++;
    }
    
    while(*str >= '0' && *str <= '9') {
        if(value > INT_MAX / 10 || (value == INT_MAX / 10 && *str - '0' > 7)) return sign == 1 ? INT_MAX : INT_MIN;
        value = value * 10 + (*str - '0');
        str++;
    }
    return value * sign;
}
