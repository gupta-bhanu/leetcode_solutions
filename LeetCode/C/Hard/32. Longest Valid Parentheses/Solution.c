int longestValidParentheses(char* s) {
    int left = 0, right = 0, max_len = 0;
    int len = 0;
    
    // Determine string length
    while (s[len] != '\0') {
        len++;
    }

    // Pass 1: Scan from left to right
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            if (left * 2 > max_len) {
                max_len = left * 2;
            }
        } else if (right > left) {
            // More closing parentheses than opening means the current sequence is invalid
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;

    // Pass 2: Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            if (left * 2 > max_len) {
                max_len = left * 2;
            }
        } else if (left > right) {
            // Scanning backwards, more opening parentheses means the sequence is invalid
            left = 0;
            right = 0;
        }
    }

    return max_len;
}