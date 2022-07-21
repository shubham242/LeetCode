class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int index = 1;
        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *ptr = temp;
        while (ptr->next && index != left)
        {
            ptr = ptr->next;
            index++;
        }
        if (ptr->next)
        {
            ListNode *prev = NULL;
            ListNode *curr = ptr->next;
            while (index != right)
            {
                ListNode *t = curr->next;
                index++;
                curr->next = prev;
                prev = curr;
                curr = t;
            }
            ListNode *t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
            ptr->next->next = curr;
            ptr->next = prev;
        }
        return temp->next;
    }
};