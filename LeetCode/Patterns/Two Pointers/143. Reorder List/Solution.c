/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }

    // Step 1: Find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;
    slow->next = NULL; // Break the list into two halves
    struct ListNode *nxt = NULL;

    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    // Step 3: Merge the two halves alternately
    struct ListNode *first = head;
    struct ListNode *second = prev;
    struct ListNode *tmp1, *tmp2;

    while (second != NULL) {
        tmp1 = first->next;
        tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
    }
}