#include <bits/stdc++.h>

bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *fast = head;
    SinglyLinkedListNode *slow = head;
    
    while ((fast && fast->next) && slow) {
        fast = fast->next->next;
        slow = slow->next;
        if (!fast || !slow) return false;
        if (fast == slow) return true;
    }
    return false;
}
