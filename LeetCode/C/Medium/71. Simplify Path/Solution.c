char* simplifyPath(char* path) {
    // A path of length 3000 can have at most 1500 directories
    char* stack[1500]; 
    int top = -1;
    
    // Split the path by slashes
    char* token = strtok(path, "/");
    
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // Go up a directory by popping the stack
            if (top >= 0) {
                top--;
            }
        } else if (strcmp(token, ".") != 0) {
            // Ignore "." and push valid directory names to the stack
            stack[++top] = token;
        }
        token = strtok(NULL, "/");
    }
    
    // Allocate memory for the simplified path
    char* res = (char*)malloc(3001 * sizeof(char));
    res[0] = '\0';
    
    // Handle the root directory edge case
    if (top == -1) {
        strcpy(res, "/");
        return res;
    }
    
    // Reconstruct the path from the stack
    for (int i = 0; i <= top; i++) {
        strcat(res, "/");
        strcat(res, stack[i]);
    }
    
    return res;
}