/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head)
        return false;
    struct ListNode* s= head;
    struct ListNode* f= head;
    
    while(f->next&&f->next->next)
    {
        s=s->next;
        f=f->next->next;
        
        if(s==f)
            return true;
    }
    return false;
    
}