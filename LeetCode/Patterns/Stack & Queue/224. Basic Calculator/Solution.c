#include <stdlib.h>

int calculate(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    
    // Allocate stack memory. At most, we push two integers per '(' character.
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    
    int result = 0;
    long current_num = 0; // Use long to prevent overflow during digit accumulation
    int sign = 1;         // 1 represents '+', -1 represents '-'
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c >= '0' && c <= '9') {
            // Build the multi-digit number
            current_num = current_num * 10 + (c - '0');
        } else if (c == '+') {
            // Apply the previous number to the result and set the next sign to positive
            result += sign * current_num;
            current_num = 0;
            sign = 1;
        } else if (c == '-') {
            // Apply the previous number to the result and set the next sign to negative
            result += sign * current_num;
            current_num = 0;
            sign = -1;
        } else if (c == '(') {
            // We are entering a new sub-expression. 
            // Save the current running result and the sign immediately preceding the '('
            stack[++top] = result;
            stack[++top] = sign;
            
            // Reset the environment for the inner expression
            result = 0;
            sign = 1;
        } else if (c == ')') {
            // Conclude the inner expression by adding the last pending number
            result += sign * current_num;
            current_num = 0;
            
            // Pop the sign that precedes the '(' and the outer result saved before the '('
            int prev_sign = stack[top--];
            int prev_result = stack[top--];
            
            // Multiply the inner evaluated result by its associated sign, 
            // then add it back to the outer result.
            result = prev_result + (prev_sign * result);
        }
    }
    
    // Add any trailing number left after the loop finishes
    result += sign * current_num;
    
    free(stack);
    return result;
}