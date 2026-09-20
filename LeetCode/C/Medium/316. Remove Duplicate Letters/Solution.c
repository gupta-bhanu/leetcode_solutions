#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {
    int count[26] = {0};
    int visited[26] = {0};
    int len = 0;
    
    // Pass 1: Count occurrences of each character
    while (s[len] != '\0') {
        count[s[len] - 'a']++;
        len++;
    }
    
    // Stack to store the result string
    // Max 26 unique characters + 1 for null terminator
    char* stack = (char*)malloc(27 * sizeof(char));
    int top = -1;
    
    // Pass 2: Build the lexicographically smallest string
    for (int i = 0; i < len; i++) {
        int char_idx = s[i] - 'a';
        
        // Decrement the remaining count as we process the string
        count[char_idx]--;
        
        // If the character is already safely in our stack, skip it
        if (visited[char_idx]) {
            continue;
        }
        
        // Monotonic stack logic: 
        // 1. Stack is not empty
        // 2. The top character is lexicographically greater than the current one
        // 3. The top character appears again later in the string (count > 0)
        while (top >= 0 && stack[top] > s[i] && count[stack[top] - 'a'] > 0) {
            visited[stack[top] - 'a'] = 0; // Mark the popped character as unvisited
            top--; // Pop from stack
        }
        
        // Push the current character and mark it as visited
        stack[++top] = s[i];
        visited[char_idx] = 1;
    }
    
    // Null-terminate the resulting string
    stack[top + 1] = '\0';
    
    return stack;
}