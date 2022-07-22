class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *n = new ListNode(0);
        ListNode *curr = n;
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *ptr = temp;

        while (ptr)
        {
            if (ptr->next && ptr->next->val < x)
            {
                curr->next = ptr->next;
                curr = curr->next;
                ptr->next = ptr->next->next;
            }else
            ptr = ptr->next;
        }
        curr->next = temp->next;
        return n->next;
    }
};