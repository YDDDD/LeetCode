//Runtime:6ms

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *stack[10000] = {};
    struct ListNode *previous = NULL, *point = head;
    int len = 0;
    while(point || len == k) {
        if(len == k) {
            if(previous) {
                previous->next = stack[len - 1];
            } else {
                head = stack[len - 1];
            }
            for(int i = 1; i < len; i++) {
                stack[i]->next = stack[i - 1];
            }
            
            len = 0;
            previous = stack[0];
            previous->next = point;
        }
        
        if(!point) {
            previous->next = NULL;
            break;
        }
        
        stack[len++] = point;
        point = point->next;
    }
    
    return head;
}
