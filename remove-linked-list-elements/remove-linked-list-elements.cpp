class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *tmp = head;
        if(head==nullptr)
            return nullptr;

        while (head->next&&head->val == val)
        {
            head = head->next;
        }
        if(head->val==val)
            return nullptr;
        while (tmp->next != NULL)
        {
            if (tmp->next->val == val)
            {
                tmp->next = tmp->next->next;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return head;
    }
};