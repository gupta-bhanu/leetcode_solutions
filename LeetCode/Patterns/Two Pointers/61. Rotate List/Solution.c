/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // Find the length of the list and the old tail
    struct ListNode* oldTail = head;
    int length = 1;
    while (oldTail->next != NULL) {
        oldTail = oldTail->next;
        length++;
    }

    // Connect the old tail to the head to form a cycle
    oldTail->next = head;

    // Calculate effective rotations and the steps to the new tail
    int effectiveK = k % length;
    int stepsToNewTail = length - effectiveK;
    
    // Find the new tail (starting from oldTail is a convenient shortcut)
    struct ListNode* newTail = oldTail;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // The new head is just after the new tail
    struct ListNode* newHead = newTail->next;

    // Break the cycle
    newTail->next = NULL;

    return newHead;
}