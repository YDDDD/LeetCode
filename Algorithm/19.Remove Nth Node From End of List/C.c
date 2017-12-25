struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *point = head, *pervious, *foo;
    if(!head->next) {
        return NULL;
    }
    
    for(int i = 1; i < n; i++) {
        point = point->next;
        if(!point) return head->next;
    }
    pervious = head;
    while(point->next) {
        point = point->next;
        foo = pervious;
        pervious = pervious->next;
    }
    if(foo) {
        foo->next = pervious->next;
    } else {
        return head->next;
    }
    
    return head;
}
