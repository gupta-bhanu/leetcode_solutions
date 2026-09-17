/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

// Helper function to find the k-th node from a given start node
struct ListNode* getKthNode(struct ListNode* curr, int k) {
    while (curr != NULL && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* groupPrev = &dummy;

    while (1) {
        // Find the k-th node of the current group
        struct ListNode* kthNode = getKthNode(groupPrev, k);
        if (kthNode == NULL) {
            break; // Less than k nodes remaining, do not reverse
        }

        struct ListNode* groupNext = kthNode->next;
        
        // Reverse the current group
        // Initializing prev to groupNext automatically links the reversed group's tail
        struct ListNode* prev = groupNext; 
        struct ListNode* curr = groupPrev->next;
        
        while (curr != groupNext) {
            struct ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // groupPrev->next currently points to the old head (now the tail).
        // Save it to update groupPrev later.
        struct ListNode* tmp = groupPrev->next; 
        
        // Connect the previous part of the list to the new head of the reversed group
        groupPrev->next = kthNode; 
        
        // Advance groupPrev to the end of the newly reversed group
        groupPrev = tmp; 
    }

    return dummy.next;
}