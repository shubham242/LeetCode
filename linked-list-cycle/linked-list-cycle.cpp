/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* n=head;
        ListNode* p=head;
        
        while(n)
        {
            if(n->next==head) return true;
            p=n;
            n=n->next;
            p->next=head;
            
        }
        
        return false;
        
    }
};