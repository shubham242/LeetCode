/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev = NULL;
    while (head != NULL)
    {
        struct ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->next = head;
    struct ListNode *prev = res;
    int count = 1;

    while (head != NULL)
    {
        if (count % k == 0)
        {
            struct ListNode *temp = head->next;
            head->next = NULL;
            struct ListNode *temp2 = prev->next;
            prev->next = reverseList(prev->next);
            prev = temp2;
            head=temp2;
            head->next=temp;
        }
        head = head->next;
        count++;
    }

    return res->next;
}