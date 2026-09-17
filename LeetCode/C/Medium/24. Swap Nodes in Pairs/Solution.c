/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* swapPairs(struct ListNode* head) {
    // Dummy node helps handle the case where the new head becomes the second node
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // Ensure there are at least two nodes left to swap
    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to swap
        struct ListNode* first = prev->next;
        struct ListNode* second = prev->next->next;

        // Perform the pointer rewiring to swap
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move the prev pointer forward for the next iteration
        prev = first; 
    }

    return dummy.next;
}