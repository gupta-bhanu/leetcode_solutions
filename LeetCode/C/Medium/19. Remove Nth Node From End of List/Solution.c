/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy node to handle edge cases like removing the head
    struct ListNode dummy;
    dummy.next = head;
    
    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;
    
    // Move fast pointer n + 1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow is now pointing to the node immediately preceding the target
    struct ListNode *nodeToRemove = slow->next;
    slow->next = slow->next->next;
    
    // Free the memory to prevent leaks
    free(nodeToRemove);
    
    return dummy.next;
}