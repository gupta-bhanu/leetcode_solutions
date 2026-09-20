#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper to compare which array offers the larger lexicographical sequence
bool compare(int* nums1, int len1, int i, int* nums2, int len2, int j) {
    while (i < len1 && j < len2 && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    if (j == len2) return true;
    if (i == len1) return false;
    return nums1[i] > nums2[j];
}

// Helper to extract the maximum possible subsequence of length 'k' from an array
int* maxSubsequence(int* nums, int len, int k) {
    int* stack = (int*)malloc(k * sizeof(int));
    int top = -1;
    int drop = len - k; // The number of digits we are allowed to discard

    for (int i = 0; i < len; i++) {
        // Monotonic stack: drop smaller previous digits if we can afford to
        while (top >= 0 && stack[top] < nums[i] && drop > 0) {
            top--;
            drop--;
        }
        if (top < k - 1) {
            stack[++top] = nums[i];
        } else {
            drop--; // Stack is full, discard the current digit
        }
    }
    return stack;
}

// Helper to merge two sequences into the maximum possible combined number
int* merge(int* nums1, int len1, int* nums2, int len2) {
    int* res = (int*)malloc((len1 + len2) * sizeof(int));
    int i = 0, j = 0, r = 0;
    while (i < len1 || j < len2) {
        // Use lookahead comparison to break ties
        if (compare(nums1, len1, i, nums2, len2, j)) {
            res[r++] = nums1[i++];
        } else {
            res[r++] = nums2[j++];
        }
    }
    return res;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int* max_res = (int*)calloc(k, sizeof(int));
    *returnSize = k;

    // Determine the valid range of digits we can take from nums1
    int start = (k - nums2Size > 0) ? k - nums2Size : 0;
    int end = (k < nums1Size) ? k : nums1Size;

    // Test every valid combination of taking 'i' digits from nums1 and 'k - i' from nums2
    for (int i = start; i <= end; i++) {
        int* sub1 = maxSubsequence(nums1, nums1Size, i);
        int* sub2 = maxSubsequence(nums2, nums2Size, k - i);
        int* candidate = merge(sub1, i, sub2, k - i);

        // Keep the candidate if it is lexicographically larger than our current max
        if (compare(candidate, k, 0, max_res, k, 0)) {
            memcpy(max_res, candidate, k * sizeof(int));
        }

        // Free intermediate arrays to prevent memory leaks
        free(sub1);
        free(sub2);
        free(candidate);
    }

    return max_res;
}