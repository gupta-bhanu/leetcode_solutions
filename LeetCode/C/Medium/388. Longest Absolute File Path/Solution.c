#include <string.h>

int lengthLongestPath(char * input) {
    if (input == NULL) return 0;
    
    int len = strlen(input);
    // The maximum depth cannot exceed the length of the string
    int path_lens[10005] = {0}; 
    
    int max_len = 0;
    int i = 0;
    
    while (i < len) {
        int depth = 0;
        
        // Count consecutive tab characters to determine the current directory depth
        while (i < len && input[i] == '\t') {
            depth++;
            i++;
        }
        
        int current_name_len = 0;
        int is_file = 0;
        
        // Read the file or directory name until a newline or end of string
        while (i < len && input[i] != '\n') {
            if (input[i] == '.') {
                is_file = 1; // Presence of a dot indicates a file
            }
            current_name_len++;
            i++;
        }
        
        // Calculate the absolute path length up to this item
        int current_total_len = current_name_len;
        if (depth > 0) {
            // Add the length of the parent directory path plus 1 for the '/' separator
            current_total_len += path_lens[depth - 1] + 1; 
        }
        
        // Store the cumulative length for the current depth
        path_lens[depth] = current_total_len;
        
        // Only update the global maximum if the current item is a file
        if (is_file) {
            if (current_total_len > max_len) {
                max_len = current_total_len;
            }
        }
        
        // Skip the newline character to process the next item
        if (i < len && input[i] == '\n') {
            i++;
        }
    }
    
    return max_len;
}