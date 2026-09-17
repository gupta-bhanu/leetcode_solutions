/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* partition(struct ListNode* head, int x) {
    // Dummy nodes to simplify list construction
    struct ListNode lessHead;
    struct ListNode greaterHead;
    
    struct ListNode* less = &lessHead;
    struct ListNode* greater = &greaterHead;
    
    struct ListNode* curr = head;
    
    // Traverse the original list and distribute nodes
    while (curr != NULL) {
        if (curr->val < x) {
            less->next = curr;
            less = less->next;
        } else {
            greater->next = curr;
            greater = greater->next;
        }
        curr = curr->next;
    }
    
    // Terminate the greater list to avoid cycles in the combined list
    greater->next = NULL;
    
    // Stitch the two lists together
    less->next = greaterHead.next;
    
    // Return the start of the newly partitioned list
    return lessHead.next;
}