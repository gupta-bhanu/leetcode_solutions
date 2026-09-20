int calculate(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    
    long current_num = 0;
    long last_num = 0;
    long result = 0;
    char sign = '+';
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // Build the current number if the character is a digit
        if (c >= '0' && c <= '9') {
            current_num = current_num * 10 + (c - '0');
        }
        
        // If the character is an operator or we've reached the end of the string
        if ((c != ' ' && (c < '0' || c > '9')) || i == len - 1) {
            if (sign == '+') {
                result += last_num;
                last_num = current_num;
            } else if (sign == '-') {
                result += last_num;
                last_num = -current_num;
            } else if (sign == '*') {
                last_num = last_num * current_num;
            } else if (sign == '/') {
                // Integer division truncates toward zero by default in C
                last_num = last_num / current_num;
            }
            
            sign = c;
            current_num = 0;
        }
    }
    
    // Add the final remaining block to the result
    result += last_num;
    
    return (int)result;
}