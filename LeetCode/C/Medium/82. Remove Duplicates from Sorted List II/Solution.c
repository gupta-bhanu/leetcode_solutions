/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Dummy node points to the head to handle edge cases where the head is deleted
    struct ListNode dummy;
    dummy.next = head;
    dummy.val = 0; // Value doesn't matter
    
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        // If we detect a duplicate sequence
        if (curr->next != NULL && curr->val == curr->next->val) {
            
            // Advance curr to the end of the duplicate sequence
            while (curr->next != NULL && curr->val == curr->next->val) {
                struct ListNode* temp = curr;
                curr = curr->next;
                free(temp); // Free memory of duplicate nodes
            }
            
            // curr is now on the last node of the duplicates.
            // Skip it by pointing prev's next to curr's next.
            prev->next = curr->next;
            
            // Free the final node of the duplicate sequence
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
            
        } else {
            // No duplicates found, it's safe to advance prev
            prev = prev->next;
            curr = curr->next;
        }
    }

    return dummy.next;
}