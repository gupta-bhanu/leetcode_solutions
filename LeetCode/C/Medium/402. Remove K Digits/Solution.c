#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int len = 0;
    while (num[len] != '\0') {
        len++;
    }
    
    // If the number of digits to remove is equal to or greater than the string length,
    // the smallest possible integer is just "0".
    if (k >= len) {
        char* res = (char*)malloc(2 * sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    // Allocate memory for the stack (maximum possible length + null terminator)
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        // Monotonic stack logic: drop the previous digit if it is larger than 
        // the current digit, provided we still have remaining 'k' to remove.
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        
        // Push the current digit, but prevent leading zeros from entering an empty stack
        if (top >= 0 || num[i] != '0') {
            stack[++top] = num[i];
        }
    }

    // If we still need to remove digits (e.g., the digits were in increasing order like "1234")
    // we remove them from the least significant end (the top of the stack).
    while (top >= 0 && k > 0) {
        top--;
        k--;
    }

    // If removing elements left the stack entirely empty, the result is "0"
    if (top == -1) {
        stack[++top] = '0';
    }

    // Null-terminate the resulting string
    stack[top + 1] = '\0';
    
    return stack;
}