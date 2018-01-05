//runtime:6ms

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k == 0 || !head || !head->next) return head;
    struct ListNode* anchor = head, * newHead;
    int length = 0, i = 0;
    while(anchor != NULL) {
        length++;
        anchor = anchor->next; 
    }
    
    k = (length - k % length) % length;
    if(k == 0) return head;
    
    anchor = head;
    while(anchor->next != NULL) {
        if(++i == k) {
            newHead = anchor->next;
            struct ListNode* foo = anchor->next;
            anchor->next = NULL;
            anchor = foo;
        } else {
            anchor = anchor->next;
        }
    }
    anchor->next = head;
    return newHead;
}
