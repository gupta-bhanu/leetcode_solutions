/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Dummy node to represent the start of the new sorted list
    struct ListNode dummy;
    dummy.next = NULL; 
    
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        // 1. Save the next node in the original list before modifying pointers
        struct ListNode* nextNode = curr->next;
        
        // 2. Find the correct position to insert 'curr' in the sorted list
        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }
        
        // 3. Insert 'curr' between 'prev' and 'prev->next'
        curr->next = prev->next;
        prev->next = curr;
        
        // 4. Advance to the next node in the unsorted list
        curr = nextNode;
    }
    
    return dummy.next;
}