/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stddef.h>

struct ListNode *detectCycle(struct ListNode *head) {
    // Empty list or single node without cycle
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Phase 1: Detect if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            
            // Phase 2: Find the entrance to the cycle
            slow = head; // Reset slow to the beginning
            
            // Move both at the same speed until they intersect
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Both pointers now point to the start of the cycle
            return slow; 
        }
    }

    // If fast reaches NULL, there is no cycle
    return NULL;
}