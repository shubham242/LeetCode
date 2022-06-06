/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->val > l2->val)
    {
        struct ListNode *temp = l1;
        l1 = l2;
        l2 = temp;
    }
    struct ListNode *res = l1;
    while (l1 != NULL && l2!=NULL)
    {
        struct ListNode *temp = NULL;
        while (l1 != NULL && l1->val <= l2->val)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;

        struct ListNode *swap = l1;
        l1 = l2;
        l2 = swap;
    }

    return res;
}